#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../../include/Lib/clsString.h"
#include "../../include/Lib/clsDate.h"
#include "../../include/Core/clsPerson.h"
#include "../../include/Core/clsBankClient.h"
#include "../../data/data.h"
#include "../../include/Core/Global.h"


    bool clsBankClient::IsServerConnected() {
        return _ServerIsUp;
    }

     string clsBankClient::EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

     string clsBankClient::DecryptText(string Text, short EncryptionKey )
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    void clsBankClient::LogErrorToFile(string ErrorMessage) {

        ofstream LogFile(BankErrorsFileName, ios::app);
        if (LogFile.is_open()) {
            LogFile << "[ERROR LOG] " << ErrorMessage << endl;
            LogFile.close();
        }
    }

     clsBankClient clsBankClient::_ConvertLinetoClientObject(string Line, string Seperator )
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(clsBankClient::enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

    }

     string clsBankClient::_ConverClientObjectToLine(clsBankClient Client, string Seperator )
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += EncryptText(Client.PinCode) + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

      vector <clsBankClient> clsBankClient::_LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open(ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

     void clsBankClient::_SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open(ClientsFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void clsBankClient::_Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void clsBankClient::_AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void clsBankClient::_AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(ClientsFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }



    void clsBankClient::_Transferz(clsBankClient& Receiver, double Amount) {

        // 1. Initial connection check
        if (!IsServerConnected())
        {
            LogErrorToFile("Transfer Error: The system is currently unavailable.");
            throw runtime_error("The system is currently unavailable.");
        }

        // 2. Logical and business rule validation
        if (Amount <= 0) {

            LogErrorToFile("Transfer Error: Invalid amount. Transfer amount must be greater than zero.");
            throw invalid_argument("Invalid amount. Transfer amount must be greater than zero.");
        }

        if (Amount > AccountBalance) {
            LogErrorToFile("Transfer Error: Insufficient balance. Your account balance is insufficient.");
            throw runtime_error("Insufficient balance. Your account balance is insufficient.");
        }

        // 🛑 التعديل والإصلاح هنا: التحقق من عدم التحويل لنفس الحساب
        if (Receiver.AccountNumber() == AccountNumber()) {
            LogErrorToFile("Transfer Error: Sender and Receiver account numbers are identical.");
            throw runtime_error("Transaction denied. You cannot transfer money to your own account.");
        }

        bool IsDebited = false;

        try {
            // Step A: Debit from the sender
            Withdraw(Amount);
            IsDebited = true;

            // Step B: Check server status mid-transaction
            if (!IsServerConnected()) {

                LogErrorToFile("Transfer Error: Server connection lost during transaction processing!");
                throw runtime_error("Server connection lost during transaction processing!");
            }

            // Step C: Credit to the receiver
            Receiver.Deposit(Amount);
        }
        catch (const exception& e) {
            // Log the technical error details silently for developers
            LogErrorToFile(e.what());

            // 🚨 Rollback Mechanism
            if (IsDebited) {
                Deposit(Amount); // Return funds to sender
                LogErrorToFile("Rollback activated: Funds returned to the sender to secure data.");
            }

            // Pass a secure, user-friendly English message to the UI Screen
            throw runtime_error("A technical error occurred. The transaction was safely cancelled, and your funds have been fully returned.");
        }
    }


     clsBankClient clsBankClient::_GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }




     clsBankClient::stTrnsferLogRecord clsBankClient::_ConvertTransferLogLineToRecord(string Line, string Seperator )
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

        return TrnsferLogRecord;


    }

    string clsBankClient::_PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient, string UserName, string Seperator )
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferLogRecord += AccountNumber() + Seperator;
        TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferLogRecord += UserName;
        return TransferLogRecord;
    }

    void clsBankClient::_RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
    {

        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open(TransFerLogFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }




    clsBankClient::clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool clsBankClient::IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool clsBankClient::MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string clsBankClient::AccountNumber()
    {
        return _AccountNumber;
    }

    void clsBankClient::SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string clsBankClient::GetPinCode()
    {
        return _PinCode;
    }

    void clsBankClient::SetAccountBalance(double AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    double clsBankClient::GetAccountBalance()
    {
        return _AccountBalance;
    }


     clsBankClient clsBankClient::Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open(ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

     clsBankClient clsBankClient::Find(string AccountNumber, string PinCode)
    {


        PinCode = EncryptText(PinCode);

        fstream MyFile;
        MyFile.open(ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

     clsBankClient::enSaveResults clsBankClient::Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

        return enSaveResults::svWarning;

    }

     bool clsBankClient::IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool clsBankClient::Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    void clsBankClient::Transferz(clsBankClient& Receiver, double Amount) {

        _Transferz(Receiver, Amount);

        _RegisterTransferLog(Amount, Receiver, CurrentUser.UserName);


    }

     clsBankClient clsBankClient::GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

     vector <clsBankClient> clsBankClient::GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

     double clsBankClient::GetTotalBalances()
    {
        vector <clsBankClient> vClients = GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }

    void clsBankClient::Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool clsBankClient::Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }

    }


      vector <clsBankClient::stTrnsferLogRecord> clsBankClient::GetTransfersLogList()
    {
        vector <stTrnsferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open(TransFerLogFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTrnsferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);

            }

            MyFile.close();

        }

        return vTransferLogRecord;

    }



      
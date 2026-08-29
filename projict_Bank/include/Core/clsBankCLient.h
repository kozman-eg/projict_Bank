#pragma once
#include <iostream>
#include <string>
#include <vector>   // Include the vector library to use std::vector for dynamic arrays ReadNumberBetween
#include "clsPerson.h"

//#include <vector>

using namespace std;
class clsBankClient : public clsPerson
{

public:

    struct stTrnsferLogRecord
    {
        string DateTime = "";
        string SourceAccountNumber = "";
        string DestinationAccountNumber = "";
        double Amount = 0;
        double srcBalanceAfter = 0;
        double destBalanceAfter = 0;
        string UserName = "";

    };

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

private:

    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;


    bool _ServerIsUp = true;

    bool IsServerConnected();




    static string EncryptText(string Text, short EncryptionKey = 5);

    static string DecryptText(string Text, short EncryptionKey = 5);

    void LogErrorToFile(string ErrorMessage); 
    
    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#");

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#");

    static  vector <clsBankClient> _LoadClientsDataFromFile();

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients);

    void _Update();

    void _AddNew();

    void _AddDataLineToFile(string  stDataLine);



    void _Transferz(clsBankClient& Receiver, double Amount);


    static clsBankClient _GetEmptyClientObject();


    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#");

    string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#");

    void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName);


public:


    clsBankClient(  enMode Mode,
                    string FirstName,
                    string LastName,
                    string Email,
                    string Phone,
                    string AccountNumber,
                    string PinCode,
                    float AccountBalance
                   );

    bool IsEmpty();

    bool MarkedForDeleted();

    string AccountNumber();

    void SetPinCode(string PinCode);

    string GetPinCode();
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(double AccountBalance);

    double GetAccountBalance();
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;


    static clsBankClient Find(string AccountNumber);

    static clsBankClient Find(string AccountNumber, string PinCode);

    enum enSaveResults { svWarning = -1, svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save();

    static bool IsClientExist(string AccountNumber);

    bool Delete();
    

    void Transferz(clsBankClient& Receiver, double Amount);

    static clsBankClient GetAddNewClientObject(string AccountNumber);
    static vector <clsBankClient> GetClientsList();

    static double GetTotalBalances();

    void Deposit(double Amount);

    bool Withdraw(double Amount);


    static  vector <stTrnsferLogRecord> GetTransfersLogList();
};

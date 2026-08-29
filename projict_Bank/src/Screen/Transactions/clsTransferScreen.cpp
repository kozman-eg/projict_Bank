#pragma once
#include <iostream>
#include <iomanip>
#include "../../../include/Screen/Transactions/clsTransferScreen.h"
#include "../../../include/Core/clsBankClient.h"
#include "../../../include/Lib/clsInputValidate.h"

void clsTransferScreen::_PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

     string clsTransferScreen::_ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

     double clsTransferScreen::ReadAmount(clsBankClient SourceClient)
    {
        double Amount;

        Amount = clsInputValidate::ReadNumber<double>("\nEnter Transfer Amount? ");

        while (Amount > SourceClient.AccountBalance || Amount <= 0)
        {
            Amount = clsInputValidate::ReadNumber<double>("\nAmount Exceeds the available Balance, Enter another Amount ? ");
        }
        return Amount;
    }


     void clsTransferScreen::ShowTransferScreen()
    {


        string Title = "\tTransfer Screen";
        _DrawScreenHeader(Title);


        clsBankClient Sender = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(Sender);


        clsBankClient Receiver = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(Receiver);



        try {

            double Amount = ReadAmount(Sender);


            char Answer = 'n';

            Answer = clsInputValidate::ReadChar("\nAre you sure you want to perform this operation? y/n? ");


            if (Answer == 'y' || Answer == 'Y')
            {
                Sender.Transferz(Receiver, Amount);


                cout << "Transferz done successfully\n";

                _PrintClient(Sender);

                _PrintClient(Receiver);
                Sender.Save();
                Receiver.Save();

            }

        }
        /*
        
      catch (const invalid_argument& e) {
    cout << "\n[Warning] Please verify the entered data! -> " << e.what() << endl;
}
catch (const runtime_error& e) {
    cout << "\n[System Error] Operation failed due to account status or server issue! -> " << e.what() << endl;
}
catch (const out_of_range& e) {
    cout << "\n[Range Error] Attempted to access a non-existent client! -> " << e.what() << endl;
}
catch (const exception& e) {
    cout << "\n[Unexpected Error] An unexpected error occurred: " << e.what() << endl;
}

        
        */
        catch (const exception& e) {
            cout << "\n[Error] Operation Failed!" << endl;
            cout << "Reason from Server: " << e.what() << endl;
        }


    }

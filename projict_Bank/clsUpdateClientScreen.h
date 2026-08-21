#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen :protected clsScreen

{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    enum enPrmacionUpdate
    {
        All = -1,
        FirstName = 1,
        LastName = 2,
        Email = 4,
        Phone = 8,
        PinCode = 16,
        Account_Balance = 32,

    };


    static short ReadenPrmacionUpdate()
    {


        char Answer = 'n';

        Answer = clsInputValidate::ReadChar("\nDo you want to give full access? y/n? ");

        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        system("cls");

        cout << "===========================================\n";
        cout << "\t\tScreen\n";
        cout << "===========================================\n";
        cout << "\t[1] FirstName\n";
        cout << "\t[2] LastName\n";
        cout << "\t[3] Email\n";
        cout << "\t[4] Phone\n";
        cout << "\t[5] PinCode\n";
        cout << "\t[6] Account_Balance\n";
        cout << "===========================================\n";


        vector<string> ClientScreens = { "FirstName", "LastName", "Email", "Phone", "PinCode", "Account_Balance" };



        return   clsInputValidate::ReadPermissionsDynamic(ClientScreens);

       /* return clsInputValidate::ReadPermissionsFromUser();

        return clsUtil::CalculateTotalPermissions(
            clsUtil::ConvertStringVectorToIntVector(
                clsString::Split(clsInputValidate::ReadString(), " ")
            )
        );*/

    };


    static void ReadClientInfo(clsBankClient& Client)
    {

        enPrmacionUpdate Permissions = (enPrmacionUpdate)ReadenPrmacionUpdate();

        if ((enPrmacionUpdate::FirstName & Permissions) == enPrmacionUpdate::FirstName)
        {
            Client.FirstName = clsInputValidate::ReadString("\nEnter FirstName: ");
        }

        if ((enPrmacionUpdate::FirstName & Permissions) == enPrmacionUpdate::FirstName)
        {
            Client.LastName = clsInputValidate::ReadString("\nEnter LastName: ");
        }

        if ((enPrmacionUpdate::FirstName & Permissions) == enPrmacionUpdate::FirstName)
        {
            Client.Email = clsInputValidate::ReadString("\nEnter Email: ");
        }
        if ((enPrmacionUpdate::FirstName & Permissions) == enPrmacionUpdate::FirstName)
        {
            Client.Phone = clsInputValidate::ReadString("\nEnter Phone: ");

        }
        if ((enPrmacionUpdate::FirstName & Permissions) == enPrmacionUpdate::FirstName)
        {
            Client.PinCode = clsInputValidate::ReadString("\nEnter PinCode: ");

        }
        if ((enPrmacionUpdate::FirstName & Permissions) == enPrmacionUpdate::FirstName)
        {
            Client.AccountBalance = clsInputValidate::ReadNumber<float>("\nEnter Account Balance: ");


        }

    }

public:

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        AccountNumber = clsInputValidate::ReadString("\nPlease Enter client Account Number: ");

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidate::ReadString("\nAccount number is not found, choose another one: ");
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);


        char Answer = 'n';
         Answer = clsInputValidate::ReadChar("\nAre you sure you want to update this client y/n? ");;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

#pragma once
#include <iostream>
#include "../../include/Core/Global.h"
#include "../../include/Screen/clsMainScreen.h"
#include "../../include/Screen/Client/clsClientListScreen.h"
#include "../../include/Screen/Client/clsAddNewClientScreen.h"
#include "../../include/Screen/Client/clsDeleteClientScreen.h"
#include "../../include/Screen/Client/clsUpdateClientScreen.h"
#include "../../include/Screen/Client/clsFindClientScreen.h"
#include "../../include/Screen/Transactions/clsTransactionsScreen.h"
#include "../../include/Screen/User/clsManageUsersScreen.h"
#include "../../include/Screen/User/clsShowLoginRegisterScreen.h"
#include "../../include/Screen/User/clsLoginRegisterScreen.h"
#include "../../include/Screen/Currencies/clsCurrencyExchangeMainScreen.h"


using namespace std;





     short clsMainScreen::_ReadMainMenueOption()
    {
       cout <<  setw(37) <<  left << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 10, "Choose what do you want to do [ %d to %d ] ");
        return Choice;
    }

      void clsMainScreen::_GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        //ShowMainMenue();
    }

     void clsMainScreen::_ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();


    }

     void clsMainScreen::_ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

     void clsMainScreen::_ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

     void clsMainScreen::_ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();


    }

     void clsMainScreen::_ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();


    }

     void clsMainScreen::_ShowTransactionsMenue()
    {
        // cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();

    }

     void clsMainScreen::_ShowManageUsersMenue()
    {
        // cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenue();

    }
    /* bool _Login()
    {
        // cout << "\nUsers Menue Will be here...\n";
        return clsLoginScreen::ShowLoginScreen();

    }*/
     void clsMainScreen::_ShowLoginRegisterScreen()
    {
        // cout << "\nUsers Menue Will be here...\n";
        clsShowLoginRegisterScreen::ShowUsersLogsList();
        //clsLoginRegisterScreen::ShowLoginRegisterScreen();

    }

     void clsMainScreen::_ShowCurrencyExchangeMainScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }

     void clsMainScreen::_Logout()
    {

        CurrentUser = clsUser::Find("", "");

        //then it will go back to main function.
    }

     void clsMainScreen::_PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;


        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrncyExchange:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            //Login();

            break;
        }

    }

     void clsMainScreen::ShowMainMenue()
    {


        short Choice = 0;

        do
        {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        Choice = _ReadMainMenueOption();

        _PerfromMainMenueOption((enMainMenueOptions)Choice);

        } while (Choice != 10);

    }



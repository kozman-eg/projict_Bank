#pragma once
#include <iostream>
#include <iomanip>
#include "../../../include/Screen/Transactions/clsTransactionsScreen.h"
#include "../../../include/Screen/Transactions/clsDepositScreen.h"
#include "../../../include/Screen/Transactions/clsWithdrawScreen.h"
#include "../../../include/Screen/Transactions/clsTotalBalancesScreen.h"
#include "../../../include/Screen/Transactions/clsTransferLogScreen.h"
#include "../../../include/Screen/Transactions/clsTransferScreen.h"
#include "../../../include/Lib/clsInputValidate.h"


using namespace std;

     short clsTransactionsScreen::ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6 ");
        return Choice;
    }



     void clsTransactionsScreen::_ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::ShowDepositScreen();
    }

     void clsTransactionsScreen::_ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

     void clsTransactionsScreen::_ShowTotalBalancesScreen()
    {
        // cout << "\n Balances Screen will be here.\n";
        clsTotalBalancesScreen::ShowTotalBalances();

    } void clsTransactionsScreen::_ShowTransferzScreen()
    {
        // cout << "\n Balances Screen will be here.\n";
        clsTransferScreen::ShowTransferScreen();

    }
     void clsTransactionsScreen::_ShowTransferLogScreen()
    {
        //cout << "\n Transfer Screen will be here.\n";
        clsTransferLogScreen::ShowTransferLogScreen();

    }
     void clsTransactionsScreen::_GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        //ShowTransactionsMenue();

    }

     void clsTransactionsScreen::_PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowTransferz:
        {
            system("cls");
            _ShowTransferzScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }






     void clsTransactionsScreen::ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        short Choice = 0;

        do
        {

            system("cls");
            _DrawScreenHeader("\t\tMain Screen");

            system("cls");
            _DrawScreenHeader("\t  Transactions Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposit.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
            cout << setw(37) << left << "" << "\t[4] Transferz.\n";
            cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";


            Choice = ReadTransactionsMenueOption();

            _PerformTransactionsMenueOption((enTransactionsMenueOptions)Choice);

        } while (Choice != 6);



        
    }




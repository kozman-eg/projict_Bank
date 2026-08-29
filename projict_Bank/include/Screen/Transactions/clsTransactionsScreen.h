#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"


using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eShowTransferz = 4, eTransferLog = 5,
        eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption();



    static void _ShowDepositScreen();

    static void _ShowWithdrawScreen();

    static void _ShowTotalBalancesScreen();
    
    static void _ShowTransferzScreen();

    static void _ShowTransferLogScreen();

    static void _GoBackToTransactionsMenue();

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption);



public:


    static void ShowTransactionsMenue();

};


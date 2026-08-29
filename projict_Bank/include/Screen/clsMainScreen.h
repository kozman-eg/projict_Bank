#pragma once
#include <iostream>
#include "clsScreen.h"


using namespace std;



class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8,eCurrncyExchange = 9, eExit = 10
    };
    ;
    static short _ReadMainMenueOption();

    static  void _GoBackToMainMenue();

    static void _ShowAllClientsScreen();

    static void _ShowAddNewClientsScreen();

    static void _ShowDeleteClientScreen();

    static void _ShowUpdateClientScreen();

    static void _ShowFindClientScreen();

    static void _ShowTransactionsMenue();

    static void _ShowManageUsersMenue();

    static void _ShowLoginRegisterScreen();

    static void _ShowCurrencyExchangeMainScreen();

    static void _Logout();

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption);

public:
    static void ShowMainMenue();
};


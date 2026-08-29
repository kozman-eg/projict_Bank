#pragma once
#include <iomanip>
#include <iostream>
#include "../clsScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen :protected clsScreen
{

private:
    enum enCurrenciesMainMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short ReadCurrenciesMainMenueOptions();

    static void _GoBackToCurrenciesMenue();

    static void _ShowCurrenciesListScreen();

    static void _ShowFindCurrencyScreen();

    static void _ShowUpdateCurrencyRateScreen();

    static void _ShowCurrencyCalculatorScreen();

    static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions);

public:

    static void ShowCurrenciesMenue();

};

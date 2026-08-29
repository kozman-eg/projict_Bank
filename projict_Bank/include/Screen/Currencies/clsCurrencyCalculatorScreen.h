#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"

class clsCurrencyCalculatorScreen :protected clsScreen

{
private:

    static float _ReadAmount();

    static clsCurrency _GetCurrency(string Message);


    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:");

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2);


public:

    static void ShowCurrencyCalculatorScreen();
};

#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"

class clsFindCurrencyScreen :protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency);

    static void _ShowResults(clsCurrency Currency);

public:

    static void ShowFindCurrencyScreen();

};

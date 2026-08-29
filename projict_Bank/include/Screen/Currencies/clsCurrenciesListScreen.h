#pragma once

#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen :protected clsScreen
{

private:
    static void PrintCurrencyRecordLine(clsCurrency Currency);

public:


    static void ShowCurrenciesListScreen();
};

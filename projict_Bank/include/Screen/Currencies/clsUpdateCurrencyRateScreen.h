#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"

class clsUpdateCurrencyRateScreen :protected clsScreen

{
private:

    static float _ReadRate();

    static void _PrintCurrency(clsCurrency Currency);

public:

    static void ShowUpdateCurrencyRateScreen();
};

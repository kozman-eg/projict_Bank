#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
#include "../../Lib/clsUtil.h"
#include <iomanip>

class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void PrintClientRecordBalanceLine(clsBankClient Client);

public:

    static void ShowTotalBalances();

};


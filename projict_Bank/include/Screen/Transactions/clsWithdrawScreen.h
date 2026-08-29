#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client);

    static string _ReadAccountNumber();

public:

    static void ShowWithdrawScreen();

};


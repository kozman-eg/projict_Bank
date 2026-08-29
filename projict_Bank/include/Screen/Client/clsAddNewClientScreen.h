#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
#include "../../Core/Global.h"


class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client);

    static void _PrintClient(clsBankClient Client);

public:

    static void ShowAddNewClientScreen();

};

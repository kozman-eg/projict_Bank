#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"

class clsUpdateClientScreen :protected clsScreen

{
private:

    static void _PrintClient(clsBankClient Client);

    enum enPrmacionUpdate
    {
        All = -1,
        FirstName = 1,
        LastName = 2,
        Email = 4,
        Phone = 8,
        PinCode = 16,
        Account_Balance = 32,

    };


    static short ReadenPrmacionUpdate();


    static void ReadClientInfo(clsBankClient& Client);

public:

    static void ShowUpdateClientScreen();
};

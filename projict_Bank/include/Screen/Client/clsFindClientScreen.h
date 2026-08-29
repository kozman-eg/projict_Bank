#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
#include "../../Lib/clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client);

public:

    static void ShowFindClientScreen();

};

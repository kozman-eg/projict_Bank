#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"

class clsDeleteClientScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client);

public:
    static void ShowDeleteClientScreen();

};

#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsUser.h"


class clsDeleteUserScreen :protected clsScreen
{

private:
    static void _PrintUser(clsUser User);

public:
    static void ShowDeleteUserScreen();

};

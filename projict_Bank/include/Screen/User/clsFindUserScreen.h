#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsUser.h"


class clsFindUserScreen :protected clsScreen
{

private:
    static void _PrintUser(clsUser User);

public:

    static void ShowFindUserScreen();

};

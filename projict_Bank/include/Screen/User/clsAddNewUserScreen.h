#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsUser.h"


class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User);

    static void _PrintUser(clsUser User);

    static int _ReadPermissionsToSet();

public:

    static void ShowAddNewUserScreen();

};

#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsUser.h"


class clsUpdateUserScreen :protected clsScreen

{
private:


    static void _ReadUserInfo(clsUser& User);

    static void _PrintUser(clsUser User);

    static int _ReadPermissionsToSet();

public:

    static void ShowUpdateUserScreen();
};

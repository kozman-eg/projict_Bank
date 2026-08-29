#pragma once
#include <iostream>
#include "../../include/Core/clsUser.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "");

    static bool CheckAccessRights(clsUser::enPermissions Permission);

};

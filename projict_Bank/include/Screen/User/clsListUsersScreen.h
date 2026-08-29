#pragma once

#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsUser.h"


class clsListUsersScreen :protected clsScreen
{

private:
    static void _PrintUserRecordLine(clsUser User);

public:

    static void ShowUsersList();

};

#pragma once

#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsUserLog.h"


class clsShowLoginRegisterScreen :protected clsScreen
{

private:
    static void _PrintUserRecordLine(clsUserLog UserLog);

public:

    static void ShowUsersLogsList();

};


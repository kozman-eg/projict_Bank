#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsUser.h"

class clsLoginRegisterScreen :protected clsScreen
{

private:

    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord);

public:

    static void ShowLoginRegisterScreen();

};

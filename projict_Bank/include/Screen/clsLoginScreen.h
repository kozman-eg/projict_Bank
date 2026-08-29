#pragma once

#include <iostream>
#include "clsScreen.h"


class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login();
public:
    static bool ShowLoginScreen();

};

#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsUser.h"


using namespace std;

class clsManageUsersScreen :protected clsScreen
{

private:
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadManageUsersMenueOption();

    static void _GoBackToManageUsersMenue();

    static void _ShowListUsersScreen();

    static void _ShowAddNewUserScreen();

    static void _ShowDeleteUserScreen();

    static void _ShowUpdateUserScreen();

    static void _ShowFindUserScreen();


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption);



public:


    static void ShowManageUsersMenue();

};

#pragma once
#include <iostream>
#include <iomanip>

#include "../../../include/Screen/User/clsManageUsersScreen.h"
#include "../../../include/Screen/User/clsListUsersScreen.h"
#include "../../../include/Screen/User/clsAddNewUserScreen.h"
#include "../../../include/Screen/User/clsDeleteUserScreen.h"
#include "../../../include/Screen/User/clsUpdateUserScreen.h"
#include "../../../include/Screen/User/clsFindUserScreen.h"
#include "../../../include/Core/clsUser.h"
#include "../../../include/Lib/clsInputValidate.h"






     short clsManageUsersScreen::ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

     void clsManageUsersScreen::_GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        // ShowManageUsersMenue();
    }

     void clsManageUsersScreen::_ShowListUsersScreen()
    {
        //cout << "\nList Users Screen Will Be Here.\n";
        clsListUsersScreen::ShowUsersList();

    }

     void clsManageUsersScreen::_ShowAddNewUserScreen()
    {
        // cout << "\nAdd New User Screen Will Be Here.\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

     void clsManageUsersScreen::_ShowDeleteUserScreen()
    {
        // cout << "\nDelete User Screen Will Be Here.\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

     void clsManageUsersScreen::_ShowUpdateUserScreen()
    {

        // cout << "\nUpdate User Screen Will Be Here.\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

     void clsManageUsersScreen::_ShowFindUserScreen()
    {

        //cout << "\nFind User Screen Will Be Here.\n";
        clsFindUserScreen::ShowFindUserScreen();
    }


     void clsManageUsersScreen::_PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }





     void clsManageUsersScreen::ShowManageUsersMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;// this will exit the function and it will not continue
        }

        short Choice = 0;

        do
        {

        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";



        Choice = ReadManageUsersMenueOption();

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)Choice);

        } while (Choice != 6);

    }


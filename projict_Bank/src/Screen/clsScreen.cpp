#pragma once
#include <iostream>
#include "../../include/Core/Global.h"
#include "../../include/Core/clsUser.h"
#include "../../include/Lib/clsDate.h"
#include "../../include/Screen/clsScreen.h"

using namespace std;

     void clsScreen::_DrawScreenHeader(string Title, string SubTitle )
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";


        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
       // cout << "\t\t\t\t\tDate: " << clsDate::FormateDate(clsDate::GetSystemDate()) << "\n\n";
       
    }

     bool clsScreen::CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            system("pause>0");


            return false;
        }
        else
        {
            return true;
        }

    }


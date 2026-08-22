#pragma once

#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsUserLog.h"


class clsShowLoginRegisterScreen :protected clsScreen
{

private:
    static void _PrintUserRecordLine(clsUserLog UserLog)
    {



        cout << setw(8) << left << "" << "| " << setw(35) << left << UserLog.Date_Time;
        cout << "| " << setw(20) << left << UserLog.UserName;
        cout << "| " << setw(20) << left << UserLog.Password;
        cout << "| " << setw(10) << left << UserLog.Permissions;

    }

public:

    static void ShowUsersLogsList()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsUserLog> vUserLogs = clsUserLog::GetUserslogsList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vUserLogs.size()) + ") Record(s).";



        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUserLogs.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUserLog UserLog : vUserLogs)
            {

                _PrintUserRecordLine(UserLog);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsUser.h"

using namespace std;

class clsUserLog : public clsUser
{
private:


    string _Date_Time = "";



    static clsUserLog _ConvertLinetoUserLogObject(string Line, string Seperator = "#//#");

    static string _ConverUserLogObjectToLine(clsUserLog UserLog, string Seperator = "#//#");

    static  vector <clsUserLog> _LoadUsersLogFromFile();

    static void _SaveUsersLogsToFile(vector <clsUserLog> vUserLog);

    void _Update();

    void _AddNew();

    void _AddDataLineToFile(string  stDataLine);

    static clsUserLog _GetEmptyUserLogObject();

public:


    clsUserLog(enMode Mode, string Date_Time, string UserName, string Password, int Permissions);


    string GetDate_Time();

    void SetDate_Time(string Date_Time);

    __declspec(property(get = GetDate_Time, put = SetDate_Time)) string Date_Time;


    static clsUserLog Find(string UserName);

    static clsUserLog Find(string UserName, string Password);

    enum enSaveResults { svWarning = -1, svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save();

    static bool IsUserExist(string UserName);

    bool Delete();
    static clsUserLog GetAddNewUserObject(string UserName);

    static vector <clsUserLog> GetUserslogsList();

};

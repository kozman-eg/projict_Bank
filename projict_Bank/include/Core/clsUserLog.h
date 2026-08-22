#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "../Lib/clsString.h"
#include "../Lib/clsDate.h"
#include "clsUser.h"
#include "../../data/data.h"
#include <vector>
#include <fstream>

using namespace std;
class clsUserLog : public clsUser
{
private:


    string _Date_Time = "";



    static clsUserLog _ConvertLinetoUserLogObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserLogData;
        vUserLogData = clsString::Split(Line, Seperator);

        return clsUserLog(enMode::UpdateMode, vUserLogData[0], vUserLogData[1], vUserLogData[2], stoi(vUserLogData[3]));

    }

    static string _ConverUserLogObjectToLine(clsUserLog UserLog, string Seperator = "#//#")
    {

        string UserLogRecord = "";
        UserLogRecord += UserLog.FirstName + Seperator;
        UserLogRecord += UserLog.LastName + Seperator;
        UserLogRecord += UserLog.Email + Seperator;
        UserLogRecord += UserLog.Phone + Seperator;
        UserLogRecord += UserLog.UserName + Seperator;
        UserLogRecord += UserLog.Password + Seperator;
        UserLogRecord += to_string(UserLog.Permissions);

        return UserLogRecord;

    }

    static  vector <clsUserLog> _LoadUsersLogFromFile()
    {

        vector <clsUserLog> vUsersLogs;

        fstream MyFile;
        MyFile.open(UsersLogFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUserLog UserLog = _ConvertLinetoUserLogObject(Line);

                vUsersLogs.push_back(UserLog);
            }

            MyFile.close();

        }

        return vUsersLogs;

    }

    static void _SaveUsersLogsToFile(vector <clsUserLog> vUserLog)
    {

        fstream MyFile;
        MyFile.open(UsersLogFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUserLog U : vUserLog)
            {

                //we only write records that are not marked for delete.  
                DataLine = _ConverUserLogObjectToLine(U);
                MyFile << DataLine << endl;
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUserLog> _vUsers;
        _vUsers = _LoadUsersLogFromFile();

        for (clsUserLog& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersLogsToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserLogObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(UsersLogFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUserLog _GetEmptyUserLogObject()
    {
        return clsUserLog(enMode::EmptyMode, "", "", "", 0);
    }

public:



    clsUserLog(enMode Mode, string Date_Time, string UserName, string Password, int Permissions) :
        clsUser(Mode, "", "", "", "", UserName, Password, Permissions)

    {

        _Date_Time = Date_Time;
    }


    string GetDate_Time()
    {
        return _Date_Time;
    }

    void SetDate_Time(string Date_Time)
    {
        _Date_Time = Date_Time;
    }

    __declspec(property(get = GetDate_Time, put = SetDate_Time)) string Date_Time;




    static clsUserLog Find(string UserName)
    {
        fstream MyFile;
        MyFile.open(UsersLogFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUserLog User = _ConvertLinetoUserLogObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserLogObject();
    }

    static clsUserLog Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open(UsersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUserLog User = _ConvertLinetoUserLogObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserLogObject();
    }

    enum enSaveResults { svWarning = -1, svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUserLog::IsUserExist(UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }
        return enSaveResults::svWarning;

    }

    static bool IsUserExist(string UserName)
    {

        clsUserLog User = clsUserLog::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUserLog> _vUsers;
        _vUsers = _LoadUsersLogFromFile();

        for (clsUserLog& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersLogsToFile(_vUsers);

        *this = _GetEmptyUserLogObject();

        return true;

    }

    static clsUserLog GetAddNewUserObject(string UserName)
    {
        return clsUserLog(enMode::AddNewMode, "", UserName, "", 0);
    }

    static vector <clsUserLog> GetUserslogsList()
    {
        return _LoadUsersLogFromFile();
    }


};

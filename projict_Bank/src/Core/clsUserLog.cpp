#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../../include/Core/clsUserLog.h"


using namespace std;



clsUserLog clsUserLog::_ConvertLinetoUserLogObject(string Line, string Seperator )
    {
        vector<string> vUserLogData;
        vUserLogData = clsString::Split(Line, Seperator);

        return clsUserLog(enMode::UpdateMode, vUserLogData[0], vUserLogData[1], vUserLogData[2], stoi(vUserLogData[3]));

    }

     string clsUserLog::_ConverUserLogObjectToLine(clsUserLog UserLog, string Seperator )
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

     vector <clsUserLog> clsUserLog::_LoadUsersLogFromFile()
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

     void clsUserLog::_SaveUsersLogsToFile(vector <clsUserLog> vUserLog)
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

    void clsUserLog::_Update()
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

    void clsUserLog::_AddNew()
    {

        _AddDataLineToFile(_ConverUserLogObjectToLine(*this));
    }

    void clsUserLog::_AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(UsersLogFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

     clsUserLog clsUserLog::_GetEmptyUserLogObject()
    {
        return clsUserLog(enMode::EmptyMode, "", "", "", 0);
    }




     clsUserLog::clsUserLog(enMode Mode, string Date_Time, string UserName, string Password, int Permissions) :
        clsUser(Mode, "", "", "", "", UserName, Password, Permissions)

    {

        _Date_Time = Date_Time;
    }


    string clsUserLog::GetDate_Time()
    {
        return _Date_Time;
    }

    void clsUserLog::SetDate_Time(string Date_Time)
    {
        _Date_Time = Date_Time;
    }

     clsUserLog clsUserLog::Find(string UserName)
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

     clsUserLog clsUserLog::Find(string UserName, string Password)
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


    clsUserLog::enSaveResults clsUserLog::Save()
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

     bool clsUserLog::IsUserExist(string UserName)
    {

        clsUserLog User = clsUserLog::Find(UserName);
        return (!User.IsEmpty());
    }

    bool clsUserLog::Delete()
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

     clsUserLog clsUserLog::GetAddNewUserObject(string UserName)
    {
        return clsUserLog(enMode::AddNewMode, "", UserName, "", 0);
    }

     vector <clsUserLog> clsUserLog::GetUserslogsList()
    {
        return _LoadUsersLogFromFile();
    }



#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../../data/data.h"
#include "../../include/Lib/clsUtil.h"
#include "../../include/Lib/clsDate.h"
#include "../../include/Lib/clsString.h"
#include "../../include/Core/clsPerson.h"
#include "../../include/Core/clsUser.h"

using namespace std;

    
string clsUser::EncryptText(string Text, short EncryptionKey )
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}

 string clsUser::DecryptText(string Text, short EncryptionKey )
{

    for (int i = 0; i < Text.length(); i++)
    {

        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}



 clsUser::stLoginRegisterRecord clsUser::_ConvertLoginRegisterLineToRecord(string Line, string Seperator )
{
    stLoginRegisterRecord LoginRegisterRecord;


    vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
    LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
    LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
    LoginRegisterRecord.Password = LoginRegisterDataLine[2];
    LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

    return LoginRegisterRecord;

}




string clsUser::_PrepareLogInRecord(string Seperator )
{
    string LoginRecord = "";
    LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
    LoginRecord += UserName + Seperator;
    LoginRecord += EncryptText(Password) + Seperator;
    LoginRecord += to_string(Permissions);
    return LoginRecord;
}
 clsUser clsUser::_ConvertLinetoUserObject(string Line, string Seperator )
{
    vector<string> vUserData;
    vUserData = clsString::Split(Line, Seperator);

    return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
        vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

}

 string clsUser::_ConverUserObjectToLine(clsUser User, string Seperator )
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += EncryptText(User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }

      vector <clsUser> clsUser::_LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open(UsersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

     void clsUser::_SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open(UsersFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void clsUser::_Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void clsUser::_AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void clsUser::_AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(UsersFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }


     clsUser clsUser::_GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

       


     clsUser::clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }
    

    bool clsUser::IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool clsUser::MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string clsUser::GetUserName()
    {
        return _UserName;
    }

    void clsUser::SetUserName(string UserName)
    {
        _UserName = UserName;
    }


    void clsUser::SetPassword(string Password)
    {
        _Password = Password;
    }

    string clsUser::GetPassword()
    {
        return _Password;
    }

    void clsUser::SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int clsUser::GetPermissions()
    {
        return _Permissions;
    }


     clsUser clsUser::Find(string UserName)
    {
        fstream MyFile;
        MyFile.open(UsersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

     clsUser clsUser::Find(string UserName, string Password)
    {
        Password = EncryptText(Password);
        fstream MyFile;
        MyFile.open(UsersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }


     clsUser::enSaveResults clsUser::Save()
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
            if (clsUser::IsUserExist(_UserName))
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

     bool clsUser::IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool clsUser::Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

     clsUser clsUser::GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

     vector <clsUser> clsUser::GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool clsUser::CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if (Permission & this->Permissions)
            return true;
        else
            return false;

    }

    void clsUser::RegisterLogIn() {

            string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open(UsersLogFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
          
            MyFile << stDataLine << endl;

            MyFile.close();
        }


    }

      vector <clsUser::stLoginRegisterRecord> clsUser::GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open(UsersLogFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {

                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);

            }

            MyFile.close();

        }

        return vLoginRegisterRecord;

    }
    


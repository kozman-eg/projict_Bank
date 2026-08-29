#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "../../data/data.h"
#include "../Lib/clsString.h"
#include "../Lib/clsDate.h"
#include "../Lib/clsUtil.h"
#include <vector>
#include <fstream>

using namespace std;
class clsUser : public clsPerson
{

public:

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pShowLogInRegister = 128
    };

    struct stLoginRegisterRecord
    {
        string DateTime = "";
        string UserName = "";
        string Password = "";
        int Permissions = 0;

    };

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enum enSaveResults { svWarning = -1, svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };


private:

    string _UserName;
    string _Password;
    int _Permissions;
    struct stLoginRegisterRecord;






    static string EncryptText(string Text, short EncryptionKey = 5);

    static string DecryptText(string Text, short EncryptionKey = 5);

    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#");




    string _PrepareLogInRecord(string Seperator = "#//#");
    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#");

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#");

    static  vector <clsUser> _LoadUsersDataFromFile();

    static void _SaveUsersDataToFile(vector <clsUser> vUsers);

    void _Update();    

    void _AddNew();

    void _AddDataLineToFile(string  stDataLine);


    static clsUser _GetEmptyUserObject();

    protected:

        enMode _Mode;
        bool _MarkedForDelete = false;

public:



    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions);

    bool IsEmpty();

    bool MarkedForDeleted();

    string GetUserName();
    void SetUserName(string UserName);

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password);
    string GetPassword();
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions);

    int GetPermissions();
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;





    static clsUser Find(string UserName);

    static clsUser Find(string UserName, string Password);


    enSaveResults Save();

    static bool IsUserExist(string UserName);

    bool Delete();

    static clsUser GetAddNewUserObject(string UserName);

    static vector <clsUser> GetUsersList();

    bool CheckAccessPermission(enPermissions Permission);

    void RegisterLogIn();

    static  vector <stLoginRegisterRecord> GetLoginRegisterList();
    

};

#pragma once
#include <iostream>
#include <string>
#include "InterfaceCommunication.h"


using namespace std;

class clsPerson : public InterfaceCommunication
{

private:
   
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
 
    clsPerson(string FirstName, string LastName, string Email, string Phone);
    

    //Property Set
    void SetFirstName(string FirstName);

    //Property Get
    string GetFirstName();

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    //Property Set
    void SetLastName(string LastName);

    //Property Get
    string GetLastName();
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    //Property Set
    void SetEmail(string Email);

    //Property Get
    string GetEmail();
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    //Property Set
    void SetPhone(string Phone);

    //Property Get
    string GetPhone();

    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;

    string FullName();

    void SendEmail(string Title, string Body);

    void SendFax(string Title, string Body);

    void SendSMS(string Title, string Body);
};


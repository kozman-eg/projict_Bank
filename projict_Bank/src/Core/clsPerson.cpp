#pragma once
#include <iostream>
#include <string>
#include "../../include/Core/clsPerson.h"


 
clsPerson::clsPerson( string FirstName, string LastName, string Email, string Phone)
    {
        
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    //Property Set
    void  clsPerson::SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string clsPerson::GetFirstName()
    {
        return _FirstName;
    }

    //Property Set
    void clsPerson::SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string clsPerson::GetLastName()
    {
        return _LastName;
    }

    //Property Set
    void clsPerson::SetEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string clsPerson::GetEmail()
    {
        return _Email;
    }

    //Property Set
    void clsPerson::SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string clsPerson::GetPhone()
    {
        return _Phone;
    }

    string clsPerson::FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void clsPerson::SendEmail(string Title, string Body)
    {

    }

    void clsPerson::SendFax(string Title, string Body)
    {

    }

    void clsPerson::SendSMS(string Title, string Body)
    {


    }



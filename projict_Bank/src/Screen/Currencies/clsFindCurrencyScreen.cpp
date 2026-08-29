#pragma once
#include <iostream>
#include "../../../include/Screen/Currencies/clsFindCurrencyScreen.h"
#include "../../../include/Core/clsCurrency.h"
#include "../../../include/Lib/clsInputValidate.h"


void clsFindCurrencyScreen::_PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

     void clsFindCurrencyScreen::_ShowResults(clsCurrency Currency)
     {
         if (!Currency.IsEmpty())
         {
             cout << "\nCurrency Found :-)\n";
             _PrintCurrency(Currency);
         }
         else
         {
             cout << "\nCurrency Was not Found :-(\n";
         }
     }


    void clsFindCurrencyScreen::ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 1;

        cin >> Answer;

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter CurrencyCode: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }






    }


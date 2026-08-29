#pragma once
#include <iostream>
#include <iomanip>
#include "../../../include/Screen/Currencies/clsCurrencyExchangeMainScreen.h"
#include "../../../include/Screen/Currencies/clsCurrencyCalculatorScreen.h"
#include "../../../include/Screen/Currencies/clsCurrenciesListScreen.h"
#include "../../../include/Screen/Currencies/clsFindCurrencyScreen.h"
#include "../../../include/Screen/Currencies/clsUpdateCurrencyRateScreen.h"
#include "../../../include/Lib/clsInputValidate.h"


 short clsCurrencyExchangeMainScreen::ReadCurrenciesMainMenueOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

     void clsCurrencyExchangeMainScreen::_GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...\n";
        system("pause>0");
        //ShowCurrenciesMenue();
    }

     void clsCurrencyExchangeMainScreen::_ShowCurrenciesListScreen()
    {
        //  cout << "\nCurriencies List Screen Will Be Here.\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();

    }

     void clsCurrencyExchangeMainScreen::_ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency Screen Will Be Here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();

    }

     void clsCurrencyExchangeMainScreen::_ShowUpdateCurrencyRateScreen()
    {
        //cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

     void clsCurrencyExchangeMainScreen::_ShowCurrencyCalculatorScreen()
     {
         // cout << "\nCurrency Calculator Screen Will Be Here.\n";
         clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

     }

     void clsCurrencyExchangeMainScreen::_PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
    {

        switch (CurrenciesMainMenueOptions)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }



     void clsCurrencyExchangeMainScreen::ShowCurrenciesMenue()
    {

      
        short Choice = 0;

        do
        {

            system("cls");
            _DrawScreenHeader("    Currancy Exhange Main Screen");


        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        Choice = ReadCurrenciesMainMenueOptions();

        _PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)Choice);

        } while (Choice != 5);

    }



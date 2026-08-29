#include "../../include/Core/clsCurrency.h"

#include "../../include/Lib/clsString.h"
#include "../../data/data.h"

#include <fstream>
#include <string>
#include <vector>


clsCurrency clsCurrency::_ConvertLineToCurrencyObject(
    std::string Line,
    std::string Separator)
{
    std::vector<std::string> vCurrencyData;

    vCurrencyData = clsString::Split(Line, Separator);

    return clsCurrency(
        enMode::UpdateMode,
        vCurrencyData[0],
        vCurrencyData[1],
        vCurrencyData[2],
        std::stof(vCurrencyData[3])
    );
}


std::string clsCurrency::_ConvertCurrencyObjectToLine(
    clsCurrency Currency,
    std::string Separator)
{
    std::string stCurrencyRecord = "";

    stCurrencyRecord += Currency.Country() + Separator;
    stCurrencyRecord += Currency.CurrencyCode() + Separator;
    stCurrencyRecord += Currency.CurrencyName() + Separator;
    stCurrencyRecord += std::to_string(Currency.Rate());

    return stCurrencyRecord;
}


std::vector<clsCurrency> clsCurrency::_LoadCurrenciesDataFromFile()
{
    std::vector<clsCurrency> vCurrencies;

    std::fstream MyFile;

    MyFile.open(CurrencyFileName, std::ios::in);

    if (MyFile.is_open())
    {
        std::string Line;

        while (std::getline(MyFile, Line))
        {
            clsCurrency Currency =
                _ConvertLineToCurrencyObject(Line);

            vCurrencies.push_back(Currency);
        }

        MyFile.close();
    }

    return vCurrencies;
}


void clsCurrency::_SaveCurrencyDataToFile(
    std::vector<clsCurrency> vCurrencies)
{
    std::fstream MyFile;

    MyFile.open(CurrencyFileName, std::ios::out);

    if (MyFile.is_open())
    {
        for (clsCurrency Currency : vCurrencies)
        {
            std::string DataLine =
                _ConvertCurrencyObjectToLine(Currency);

            MyFile << DataLine << std::endl;
        }

        MyFile.close();
    }
}


void clsCurrency::_Update()
{
    std::vector<clsCurrency> vCurrencies =
        _LoadCurrenciesDataFromFile();

    for (clsCurrency& Currency : vCurrencies)
    {
        if (Currency.CurrencyCode() == CurrencyCode())
        {
            Currency = *this;
            break;
        }
    }

    _SaveCurrencyDataToFile(vCurrencies);
}


clsCurrency clsCurrency::_GetEmptyCurrencyObject()
{
    return clsCurrency(
        enMode::EmptyMode,
        "",
        "",
        "",
        0
    );
}


clsCurrency::clsCurrency(
    enMode Mode,
    std::string Country,
    std::string CurrencyCode,
    std::string CurrencyName,
    float Rate)
{
    _Mode = Mode;
    _Country = Country;
    _CurrencyCode = CurrencyCode;
    _CurrencyName = CurrencyName;
    _Rate = Rate;
}


std::vector<clsCurrency> clsCurrency::GetAllUSDRates()
{
    return _LoadCurrenciesDataFromFile();
}


bool clsCurrency::IsEmpty()
{
    return (_Mode == enMode::EmptyMode);
}


std::string clsCurrency::Country()
{
    return _Country;
}


std::string clsCurrency::CurrencyCode()
{
    return _CurrencyCode;
}


std::string clsCurrency::CurrencyName()
{
    return _CurrencyName;
}


void clsCurrency::UpdateRate(float NewRate)
{
    _Rate = NewRate;

    _Update();
}


float clsCurrency::Rate()
{
    return _Rate;
}


clsCurrency clsCurrency::FindByCode(
    std::string CurrencyCode)
{
    CurrencyCode =
        clsString::UpperAllString(CurrencyCode);

    std::fstream MyFile;

    MyFile.open(CurrencyFileName, std::ios::in);

    if (MyFile.is_open())
    {
        std::string Line;

        while (std::getline(MyFile, Line))
        {
            clsCurrency Currency =
                _ConvertLineToCurrencyObject(Line);

            if (Currency.CurrencyCode() == CurrencyCode)
            {
                MyFile.close();

                return Currency;
            }
        }

        MyFile.close();
    }

    return _GetEmptyCurrencyObject();
}


clsCurrency clsCurrency::FindByCountry(
    std::string Country)
{
    Country =
        clsString::UpperAllString(Country);

    std::fstream MyFile;

    MyFile.open(CurrencyFileName, std::ios::in);

    if (MyFile.is_open())
    {
        std::string Line;

        while (std::getline(MyFile, Line))
        {
            clsCurrency Currency =
                _ConvertLineToCurrencyObject(Line);

            if (
                clsString::UpperAllString(
                    Currency.Country()
                ) == Country
                )
            {
                MyFile.close();

                return Currency;
            }
        }

        MyFile.close();
    }

    return _GetEmptyCurrencyObject();
}


bool clsCurrency::IsCurrencyExist(
    std::string CurrencyCode)
{
    clsCurrency Currency =
        FindByCode(CurrencyCode);

    return !Currency.IsEmpty();
}


std::vector<clsCurrency> clsCurrency::GetCurrenciesList()
{
    return _LoadCurrenciesDataFromFile();
}


float clsCurrency::ConvertToUSD(float Amount)
{
    return Amount / Rate();
}


float clsCurrency::ConvertToOtherCurrency(
    float Amount,
    clsCurrency Currency2)
{
    float AmountInUSD = ConvertToUSD(Amount);

    if (Currency2.CurrencyCode() == "USD")
    {
        return AmountInUSD;
    }

    return AmountInUSD * Currency2.Rate();
}
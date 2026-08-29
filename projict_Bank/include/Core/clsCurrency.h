#pragma once

#include <string>
#include <vector>

using namespace std;


class clsCurrency
{
private:

    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    };

    enMode _Mode;

    std::string _Country;
    std::string _CurrencyCode;
    std::string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLineToCurrencyObject(
        std::string Line,
        std::string Separator = "#//#"
    );

    static std::string _ConvertCurrencyObjectToLine(
        clsCurrency Currency,
        std::string Separator = "#//#"
    );

    static std::vector<clsCurrency> _LoadCurrenciesDataFromFile();

    static void _SaveCurrencyDataToFile(
        std::vector<clsCurrency> vCurrencies
    );

    void _Update();

    static clsCurrency _GetEmptyCurrencyObject();

    clsCurrency(
        enMode Mode,
        std::string Country,
        std::string CurrencyCode,
        std::string CurrencyName,
        float Rate
    );

public:

    static std::vector<clsCurrency> GetAllUSDRates();

    bool IsEmpty();

    std::string Country();

    std::string CurrencyCode();

    std::string CurrencyName();

    void UpdateRate(float NewRate);

    float Rate();

    static clsCurrency FindByCode(std::string CurrencyCode);

    static clsCurrency FindByCountry(std::string Country);

    static bool IsCurrencyExist(std::string CurrencyCode);

    static std::vector<clsCurrency> GetCurrenciesList();

    float ConvertToUSD(float Amount);

    float ConvertToOtherCurrency(
        float Amount,
        clsCurrency Currency2
    );
};
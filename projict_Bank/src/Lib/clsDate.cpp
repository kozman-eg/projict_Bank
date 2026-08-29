#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <vector>   // Include the vector library to use std::vector for dynamic arrays ReadNumberBetween
#include "../../include/Lib/clsString.h"
#include "../../include/Lib/clsDate.h"

using namespace std;


clsDate::clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
        _Sec = now->tm_sec;
        _Min = now->tm_min;
        _Hour = now->tm_hour;
    }

clsDate::clsDate(string sDate)
    {

        vector<string> vDate;
        vDate = clsString::Split(sDate, "/");

        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }

clsDate::clsDate(short Sec, short Min, short Hour,short Day, short Month, short Year)
    {

        _Day = Day;
        _Month = Month;
        _Year = Year;
        _Sec = Sec;
        _Min = Min;
        _Hour = Hour;
    }

clsDate::clsDate(short DateOrderInYear, short Year)
    {
        // This will construct a date by date order in year
        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date1.Day;
        _Month = Date1.Month;
        _Year = Date1.Year;
    }

clsDate::clsDate(short Day, short Minth ,short Year)
{
    _Day = Day;
    _Month = Month;
    _Year = Year;
}


void clsDate::SetSec(short Sec) { _Sec = Sec; }
short clsDate::GetSec() { return _Sec; }

void clsDate::SetMin(short Min) { _Min = Min; }
short clsDate::GetMin() { return _Min; }

void clsDate::SetHour(short Hour) { _Hour = Hour; }
short clsDate::GetHour() { return _Hour; }

void clsDate::SetDay(short Day) { _Day = Day; }
short clsDate::GetDay() { return _Day; }


void clsDate::SetMonth(short Month) { _Month = Month; }
short clsDate::GetMonth() { return _Month; }

void clsDate::SetYear(short Year) { _Year = Year; }
short clsDate::GetYear() { return _Year; }

void clsDate::Print()
{
    cout << DateToString() << endl;
}

clsDate clsDate::GetSystemDate()
{
    // system date
    time_t t = time(0);
    tm* now = localtime(&t);

    short Sec, Min, Hour, Day, Month, Year;

    Year = now->tm_year + 1900;
    Month = now->tm_mon + 1;
    Day = now->tm_mday;
    Sec = now->tm_sec;
    Min = now->tm_min;
    Hour = now->tm_hour;

    return clsDate(Sec, Min, Hour, Day, Month, Year);
}

string clsDate::GetSystemDateTimeString()
{
    //system datetime string
    time_t t = time(0);
    tm* now = localtime(&t);

    short Day, Month, Year, Hour, Minute, Second;

    Year = now->tm_year + 1900;
    Month = now->tm_mon + 1;
    Day = now->tm_mday;
    Hour = now->tm_hour;
    Minute = now->tm_min;
    Second = now->tm_sec;

    return (to_string(Day) + "/" + to_string(Month) + "/"
        + to_string(Year) + " - "
        + to_string(Hour) + ":" + to_string(Minute)
        + ":" + to_string(Second));

}

bool clsDate::IsValidDate(clsDate Date)
{

    if (Date.Day < 1 || Date.Day > 31)
        return false;

    if (Date.Month < 1 || Date.Month > 12)
        return false;

    if (Date.Month == 2)
    {
        if (isLeapYear(Date.Year))
        {
            if (Date.Day > 29)
                return false;
        }
        else
        {
            if (Date.Day > 28)
                return false;
        }
    }

    short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > DaysInMonth)
        return false;

    return true;
}

bool clsDate::IsValid()
{
    return clsDate::IsValidDate(*this);
}

string clsDate::DateToString(clsDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
string clsDate::FollDateToString(clsDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year) + " - " + to_string(Date.Hour) + ":" + to_string(Date.Min) + ":" + to_string(Date.Sec);
}

string clsDate::DateToString()
{
    return clsDate::DateToString(*this);
}

bool clsDate::isLeapYear(short Year)
{

    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool clsDate::isLeapYear()
{
    return clsDate::isLeapYear(_Year);
}

short clsDate::NumberOfDaysInAYear(short Year)
{
    return clsDate::isLeapYear(Year) ? 365 : 364;
}

short clsDate::NumberOfDaysInAYear()
{
    return clsDate::NumberOfDaysInAYear(_Year);
}

short clsDate::NumberOfHoursInAYear(short Year)
{
    return clsDate::NumberOfDaysInAYear(Year) * 24;
}

short clsDate::NumberOfHoursInAYear()
{
    return clsDate::NumberOfHoursInAYear(_Year);
}

int clsDate::NumberOfMinutesInAYear(short Year)
{
    return clsDate::NumberOfHoursInAYear(Year) * 60;
}

int clsDate::NumberOfMinutesInAYear()
{
    return clsDate::NumberOfMinutesInAYear(_Year);
}

int clsDate::NumberOfSecondsInAYear(short Year)
{
    return clsDate::NumberOfMinutesInAYear(Year) * 60;
}

int clsDate::NumberOfSecondsInAYear()
{
    return clsDate::NumberOfSecondsInAYear(_Year);
}

short clsDate::NumberOfDaysInAMonth(short Month, short Year)
{

    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (clsDate::isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short clsDate::NumberOfDaysInAMonth()
{
    return NumberOfDaysInAMonth(_Month, _Year);
}

short clsDate::NumberOfHoursInAMonth(short Month, short Year)
{
    return NumberOfDaysInAMonth(Month, Year) * 24;
}

short clsDate::NumberOfHoursInAMonth()
{
    return NumberOfDaysInAMonth(_Month, _Year) * 24;
}

int clsDate::NumberOfMinutesInAMonth(short Month, short Year)
{
    return NumberOfHoursInAMonth(Month, Year) * 60;
}

int clsDate::NumberOfMinutesInAMonth()
{
    return NumberOfHoursInAMonth(_Month, _Year) * 60;
}

int clsDate::NumberOfSecondsInAMonth(short Month, short Year)
{
    return NumberOfMinutesInAMonth(Month, Year) * 60;
}

int clsDate::NumberOfSecondsInAMonth()
{
    return NumberOfMinutesInAMonth(_Month, _Year) * 60;
}

short clsDate::DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short clsDate::DayOfWeekOrder()
{
    return clsDate::DayOfWeekOrder(_Day, _Month, _Year);
}

string clsDate::DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder];
}

string clsDate::DayShortName(short Day, short Month, short Year)
{

    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
}

string clsDate::DayShortName()
{

    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
}

string clsDate::MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec" };

    return (Months[MonthNumber - 1]);
}

string clsDate::MonthShortName()
{

    return MonthShortName(_Month);
}

void clsDate::PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;

    // Index of the day from 0 to 6
    int current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    // Print the current month name
    printf("\n  _______________%s_______________\n\n",
        MonthShortName(Month).c_str());

    // Print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print appropriate spaces
    int i;
    for (i = 0; i < current; i++)
        printf("     ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }

    printf("\n  _________________________________\n");
}

void clsDate::PrintMonthCalendar()
{
    PrintMonthCalendar(_Month, _Year);
}

void clsDate::PrintYearCalendar(int Year)
{
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", Year);
    printf("  _________________________________\n");

    for (int i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(i, Year);
    }

    return;
}

void clsDate::PrintYearCalendar()
{
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", _Year);
    printf("  _________________________________\n");

    for (int i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(i, _Year);
    }

    return;
}

short clsDate::DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{

    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

short clsDate::DaysFromTheBeginingOfTheYear()
{

    short TotalDays = 0;

    for (int i = 1; i <= _Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, _Year);
    }

    TotalDays += _Day;

    return TotalDays;
}

clsDate clsDate::GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{

    clsDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

void clsDate::AddDays(short Days)
{

    short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    short MonthDays = 0;

    _Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(_Month, _Year);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            _Month++;

            if (_Month > 12)
            {
                _Month = 1;
                _Year++;
            }
        }
        else
        {
            _Day = RemainingDays;
            break;
        }
    }
}

bool clsDate::IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool clsDate::IsDateBeforeDate2(clsDate Date2)
{
    // note: *this sends the current object :-)
    return IsDate1BeforeDate2(*this, Date2);
}

bool clsDate::IsDate1EqualDate2(clsDate Date1, clsDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool clsDate::IsDateEqualDate2(clsDate Date2)
{
    return IsDate1EqualDate2(*this, Date2);
}

bool clsDate::IsLastDayInMonth(clsDate Date)
{

    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool clsDate::IsLastDayInMonth()
{

    return IsLastDayInMonth(*this);
}

bool clsDate::IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

clsDate clsDate::AddOneDay(clsDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

void clsDate::AddOneDay()

{
    *this = AddOneDay(*this);
}

void clsDate::SwapDates(clsDate& Date1, clsDate& Date2)
{

    clsDate TempDate;
    TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
}

int clsDate::GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay)
{
    // this will take care of negative diff
    int Days = 0;
    short SawpFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        // Swap Dates
        SwapDates(Date1, Date2);
        SawpFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = AddOneDay(Date1);
    }

    return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}

int clsDate::GetDifferenceInDays(clsDate Date2, bool IncludeEndDay)
{
    return GetDifferenceInDays(*this, Date2, IncludeEndDay);
}

short clsDate::CalculateMyAgeInDays(clsDate DateOfBirth)
{
    return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
}

string clsDate::FormateDate(clsDate Date, string DateFormat )
{
    string FormattedDateString = "";
    FormattedDateString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date._Day), "/");
    FormattedDateString = clsString::ReplaceWord(FormattedDateString, "mm", to_string(Date._Month), "/");
    FormattedDateString = clsString::ReplaceWord(FormattedDateString, "yyyy", to_string(Date._Year), "/");
    return FormattedDateString;
}
// above no need to have non function for the object because it does not depend on any data from it.

clsDate clsDate::IncreaseDateByOneWeek(clsDate& Date)
{

    for (int i = 1; i <= 7; i++)
    {
        Date = AddOneDay(Date);
    }

    return Date;
}

void clsDate::IncreaseDateByOneWeek()
{
    IncreaseDateByOneWeek(*this);
}

clsDate clsDate::IncreaseDateByXWeeks(short Weeks, clsDate& Date)
{

    for (short i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

void clsDate::IncreaseDateByXWeeks(short Weeks)
{
    IncreaseDateByXWeeks(Weeks, *this);
}

clsDate clsDate::IncreaseDateByOneMonth(clsDate& Date)
{

    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    // last check day in date should not exceed max days in the current month
    //  example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
    //  be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

void clsDate::IncreaseDateByOneMonth()
{

    IncreaseDateByOneMonth(*this);
}

clsDate clsDate::IncreaseDateByXDays(short Days, clsDate& Date)
{

    for (short i = 1; i <= Days; i++)
    {
        Date = AddOneDay(Date);
    }
    return Date;
}

void clsDate::IncreaseDateByXDays(short Days)
{

    IncreaseDateByXDays(Days, *this);
}

clsDate clsDate::IncreaseDateByXMonths(short Months, clsDate& Date)
{

    for (short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

void clsDate::IncreaseDateByXMonths(short Months)
{
    IncreaseDateByXMonths(Months, *this);
}

clsDate clsDate::IncreaseDateByOneYear(clsDate& Date)
{
    Date.Year++;
    return Date;
}

void clsDate::IncreaseDateByOneYear()
{
    IncreaseDateByOneYear(*this);
}

clsDate clsDate::IncreaseDateByXYears(short Years, clsDate& Date)
{
    Date.Year += Years;
    return Date;
}

void clsDate::IncreaseDateByXYears(short Years)
{
    IncreaseDateByXYears(Years,*this);
}

clsDate clsDate::IncreaseDateByOneDecade(clsDate& Date)
{
    // Period of 10 years
    Date.Year += 10;
    return Date;
}

void clsDate::IncreaseDateByOneDecade()
{
    IncreaseDateByOneDecade(*this);
}

clsDate clsDate::IncreaseDateByXDecades(short Decade, clsDate& Date)
{
    Date.Year += Decade * 10;
    return Date;
}

void clsDate::IncreaseDateByXDecades(short Decade)
{
    IncreaseDateByXDecades(Decade, *this);
}

clsDate clsDate::IncreaseDateByOneCentury(clsDate& Date)
{
    // Period of 100 years
    Date.Year += 100;
    return Date;
}

void clsDate::IncreaseDateByOneCentury()
{
    IncreaseDateByOneCentury(*this);
}

clsDate clsDate::IncreaseDateByOneMillennium(clsDate& Date)
{
    // Period of 1000 years
    Date.Year += 1000;
    return Date;
}

clsDate clsDate::IncreaseDateByOneMillennium()
{
    return IncreaseDateByOneMillennium(*this);
}

clsDate clsDate::DecreaseDateByOneDay(clsDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {

            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }

    return Date;
}

void clsDate::DecreaseDateByOneDay()
{
    DecreaseDateByOneDay(*this);
}

clsDate clsDate::DecreaseDateByOneWeek(clsDate& Date)
{

    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

void clsDate::DecreaseDateByOneWeek()
{
    DecreaseDateByOneWeek(*this);
}

clsDate clsDate::DecreaseDateByXWeeks(short Weeks, clsDate& Date)
{

    for (short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

void clsDate::DecreaseDateByXWeeks(short Weeks)
{
    DecreaseDateByXWeeks(Weeks, *this);
}

clsDate clsDate::DecreaseDateByOneMonth(clsDate& Date)
{

    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
        Date.Month--;

    // last check day in date should not exceed max days in the current month
    // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
    // be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

void clsDate::DecreaseDateByOneMonth()
{
    DecreaseDateByOneMonth(*this);
}

clsDate clsDate::DecreaseDateByXDays(short Days, clsDate& Date)
{

    for (short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

void clsDate::DecreaseDateByXDays(short Days)
{
    DecreaseDateByXDays(Days, *this);
}

clsDate clsDate::DecreaseDateByXMonths(short Months, clsDate& Date)
{

    for (short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

void clsDate::DecreaseDateByXMonths(short Months)
{
    DecreaseDateByXMonths(Months, *this);
}

clsDate clsDate::DecreaseDateByOneYear(clsDate& Date)
{

    Date.Year--;
    return Date;
}

void clsDate::DecreaseDateByOneYear()
{
    DecreaseDateByOneYear(*this);
}

clsDate clsDate::DecreaseDateByXYears(short Years, clsDate& Date)
{

    Date.Year -= Years;
    return Date;
}

void clsDate::DecreaseDateByXYears(short Years)
{
    DecreaseDateByXYears(Years, *this);
}

clsDate clsDate::DecreaseDateByOneDecade(clsDate& Date)
{
    // Period of 10 years
    Date.Year -= 10;
    return Date;
}

void clsDate::DecreaseDateByOneDecade()
{
    DecreaseDateByOneDecade(*this);
}

clsDate clsDate::DecreaseDateByXDecades(short Decades, clsDate& Date)
{

    Date.Year -= Decades * 10;
    return Date;
}

void clsDate::DecreaseDateByXDecades(short Decades)
{
    DecreaseDateByXDecades(Decades, *this);
}

clsDate clsDate::DecreaseDateByOneCentury(clsDate& Date)
{
    // Period of 100 years
    Date.Year -= 100;
    return Date;
}

void clsDate::DecreaseDateByOneCentury()
{
    DecreaseDateByOneCentury(*this);
}

clsDate clsDate::DecreaseDateByOneMillennium(clsDate& Date)
{
    // Period of 1000 years
    Date.Year -= 1000;
    return Date;
}

void clsDate::DecreaseDateByOneMillennium()
    {
        DecreaseDateByOneMillennium(*this);
    }

     short clsDate::IsEndOfWeek(clsDate Date)
    {
        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
    }

    short clsDate::IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

     bool clsDate::IsWeekEnd(clsDate Date)
    {
        // Weekends are Fri and Sat
        short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        return (DayIndex == 5 || DayIndex == 6);
    }

    bool clsDate::IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

     bool clsDate::IsBusinessDay(clsDate Date)
    {
        // Weekends are Sun,Mon,Tue,Wed and Thur

        /*
         short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
         return  (DayIndex >= 5 && DayIndex <= 4);
        */

        // shorter method is to invert the IsWeekEnd: this will save updating code.
        return !IsWeekEnd(Date);
    }

    bool clsDate::IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

     short clsDate::DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }

    short clsDate::DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }

     short clsDate::DaysUntilTheEndOfMonth(clsDate Date1)
    {

        clsDate EndOfMontDate;
        EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
        EndOfMontDate.Month = Date1.Month;
        EndOfMontDate.Year = Date1.Year;

        return GetDifferenceInDays(Date1, EndOfMontDate, true);
    }

    short clsDate::DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

     short clsDate::DaysUntilTheEndOfYear(clsDate Date1)
    {

        clsDate EndOfYearDate;
        EndOfYearDate.Day = 31;
        EndOfYearDate.Month = 12;
        EndOfYearDate.Year = Date1.Year;

        return GetDifferenceInDays(Date1, EndOfYearDate, true);
    }

    short clsDate::DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(*this);
    }

    // i added this method to calculate business days between 2 days
     short clsDate::CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {

        short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;

            DateFrom = AddOneDay(DateFrom);
        }

        return Days;
    }

     short clsDate::CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        /*short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;

            DateFrom = AddOneDay(DateFrom);
        }*/

        return CalculateBusinessDays(DateFrom, DateTo);
    }
    // above method is eough , no need to have method for the object

     clsDate clsDate::CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {

        short WeekEndCounter = 0;

        for (short i = 1; i <= VacationDays; i++)
        {

            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = AddOneDay(DateFrom);
        }
        // to add weekends
        for (short i = 1; i <= WeekEndCounter; i++)
            DateFrom = AddOneDay(DateFrom);

        return DateFrom;
    }

     bool clsDate::IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }

    bool clsDate::IsDateAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    clsDate::enDateCompare clsDate::CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;

        /* if (IsDate1AfterDate2(Date1,Date2))PrintMonthCalendar
             return enDateCompare::After;*/

        // this is faster
        return clsDate::enDateCompare::After;
    }

    clsDate::enDateCompare clsDate::CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }


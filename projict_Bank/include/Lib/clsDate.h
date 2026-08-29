#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <vector>   // Include the vector library to use std::vector for dynamic arrays ReadNumberBetween
#include "clsString.h"

using namespace std;

class clsDate
{

private:
    short _Sec = 0;
    short _Min = 0;
    short _Hour = 0;
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:
    clsDate();
    

    clsDate(string sDate);

    clsDate(short Sec, short Min, short Hour, short Day, short Month, short Year);

    clsDate(short DateOrderInYear, short Year);

    clsDate(short Day, short Minth, short Year);

    void SetSec(short Sec);
    short GetSec();
    __declspec(property(get = GetSec, put = SetSec)) short Sec;


    void SetMin(short Min);
    short GetMin();
    __declspec(property(get = GetMin, put = SetMin)) short Min;

    void SetHour(short Hour);
    short GetHour();
    __declspec(property(get = GetHour, put = SetHour)) short Hour;

    void SetDay(short Day);
    short GetDay();
    __declspec(property(get = GetDay, put = SetDay)) short Day;


    void SetMonth(short Month);
    short GetMonth();
    __declspec(property(get = GetMonth, put = SetMonth)) short Month;

    void SetYear(short Year);
    short GetYear();
    __declspec(property(get = GetYear, put = SetYear)) short Year;

    void Print();

    static clsDate GetSystemDate();

    static string GetSystemDateTimeString();

    static bool IsValidDate(clsDate Date);

    bool IsValid();

    static string DateToString(clsDate Date);

    static string FollDateToString(clsDate Date);

    string DateToString();

    static bool isLeapYear(short Year);

    bool isLeapYear();

    static short NumberOfDaysInAYear(short Year);

    short NumberOfDaysInAYear();

    static short NumberOfHoursInAYear(short Year);

    short NumberOfHoursInAYear();

    static int NumberOfMinutesInAYear(short Year);

    int NumberOfMinutesInAYear();

    static int NumberOfSecondsInAYear(short Year);

    int NumberOfSecondsInAYear();

    static short NumberOfDaysInAMonth(short Month, short Year);

    short NumberOfDaysInAMonth();

    static short NumberOfHoursInAMonth(short Month, short Year);

    short NumberOfHoursInAMonth();

    static int NumberOfMinutesInAMonth(short Month, short Year);

    int NumberOfMinutesInAMonth();

    static int NumberOfSecondsInAMonth(short Month, short Year);

    int NumberOfSecondsInAMonth();

    static short DayOfWeekOrder(short Day, short Month, short Year);

    short DayOfWeekOrder();

    static string DayShortName(short DayOfWeekOrder);

    static string DayShortName(short Day, short Month, short Year);

    string DayShortName();

    static string MonthShortName(short MonthNumber);

    string MonthShortName();

    static void PrintMonthCalendar(short Month, short Year);

    void PrintMonthCalendar();

    static void PrintYearCalendar(int Year);

    void PrintYearCalendar();

    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year);

    short DaysFromTheBeginingOfTheYear();

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year);

    void AddDays(short Days);

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2);

    bool IsDateBeforeDate2(clsDate Date2);

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2);

    bool IsDateEqualDate2(clsDate Date2);

    static bool IsLastDayInMonth(clsDate Date);

    bool IsLastDayInMonth();

    static bool IsLastMonthInYear(short Month);

    static clsDate AddOneDay(clsDate Date);

    void AddOneDay();

    static void SwapDates(clsDate& Date1, clsDate& Date2); 

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false);

    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false);

    static short CalculateMyAgeInDays(clsDate DateOfBirth);

    static string FormateDate(clsDate Date, string DateFormat = "dd/mm/yyyy");

    static clsDate IncreaseDateByOneWeek(clsDate& Date);

    void IncreaseDateByOneWeek();

    clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date);

    void IncreaseDateByXWeeks(short Weeks);

    clsDate IncreaseDateByOneMonth(clsDate& Date);

    void IncreaseDateByOneMonth();

    clsDate IncreaseDateByXDays(short Days, clsDate& Date);

    void IncreaseDateByXDays(short Days);

    clsDate IncreaseDateByXMonths(short Months, clsDate& Date);

    void IncreaseDateByXMonths(short Months);

    static clsDate IncreaseDateByOneYear(clsDate& Date);

    void IncreaseDateByOneYear();

    clsDate IncreaseDateByXYears(short Years, clsDate& Date);

    void IncreaseDateByXYears(short Years);

    clsDate IncreaseDateByOneDecade(clsDate& Date);

    void IncreaseDateByOneDecade();

    clsDate IncreaseDateByXDecades(short Decade, clsDate& Date);

    void IncreaseDateByXDecades(short Decade);

    clsDate IncreaseDateByOneCentury(clsDate& Date);

    void IncreaseDateByOneCentury();

    clsDate IncreaseDateByOneMillennium(clsDate& Date);

    clsDate IncreaseDateByOneMillennium();

    static clsDate DecreaseDateByOneDay(clsDate Date);

    void DecreaseDateByOneDay();

    static clsDate DecreaseDateByOneWeek(clsDate& Date);

    void DecreaseDateByOneWeek();

    static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date);

    void DecreaseDateByXWeeks(short Weeks);

    static clsDate DecreaseDateByOneMonth(clsDate& Date);

    void DecreaseDateByOneMonth();

    static clsDate DecreaseDateByXDays(short Days, clsDate& Date);

    void DecreaseDateByXDays(short Days);

    static clsDate DecreaseDateByXMonths(short Months, clsDate& Date);

    void DecreaseDateByXMonths(short Months);

    static clsDate DecreaseDateByOneYear(clsDate& Date);

    void DecreaseDateByOneYear();

    static clsDate DecreaseDateByXYears(short Years, clsDate& Date);

    void DecreaseDateByXYears(short Years);

    static clsDate DecreaseDateByOneDecade(clsDate& Date);

    void DecreaseDateByOneDecade();

    static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date);

    void DecreaseDateByXDecades(short Decades);

    static clsDate DecreaseDateByOneCentury(clsDate& Date);

    void DecreaseDateByOneCentury();

    static clsDate DecreaseDateByOneMillennium(clsDate& Date);

    void DecreaseDateByOneMillennium();

    static short IsEndOfWeek(clsDate Date);

    short IsEndOfWeek();

    static bool IsWeekEnd(clsDate Date);

    bool IsWeekEnd();

    static bool IsBusinessDay(clsDate Date);

    bool IsBusinessDay();

    static short DaysUntilTheEndOfWeek(clsDate Date);

    short DaysUntilTheEndOfWeek();

    static short DaysUntilTheEndOfMonth(clsDate Date1);

    short DaysUntilTheEndOfMonth();

    static short DaysUntilTheEndOfYear(clsDate Date1);

    short DaysUntilTheEndOfYear();

    // i added this method to calculate business days between 2 days
    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo);

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo);

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays);

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2);

    bool IsDateAfterDate2(clsDate Date2);

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2);

    enDateCompare CompareDates(clsDate Date2);    
};


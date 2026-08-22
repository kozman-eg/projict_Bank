#pragma once
#include <iostream> // Include the iostream library for input/output operations
#include <string>   // Include the string library to work with std::string
#include <cmath>    // Include the cmath library for mathematical functions like round()
#include <vector>   // Include the vector library to use std::vector for dynamic arrays ReadNumberBetween
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <algorithm> // ضرورية لاستخدام remove_if   ReplaceWordInString

using namespace std;

class clsCheck
{
private:
    /* data */
public:
    static bool IsNumberInRange(short num, short from, short to)
    {
        return (num >= from && num <= to);
    }

    static bool IsPrime(int Number)
    {
        int N = (int)round(Number / 2);

        for (int Counter = 2; Counter <= N; Counter++)
        {
            if (Number % Counter == 0)
                return false;
        }
        return true;
    }

    static bool IsPerfectNumber(int Number)
    {
        int Sum = 0;

        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
                Sum += i;
        }

        return Number == Sum;
    }
    template <typename T>
    static short FindPositionInArray(T arr[], int arrLength, T Target)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Target)
                return i;
        }

        return -1;
    }
    template <typename T>
    static bool IsItemInArray(T arr[], T Item, int arrLength)
    {
        return FindPositionInArray(Item, arr, arrLength) != -1;
    }

    template <typename T>
    static bool IsItemInVector(vector<T> varr, T Target)
    {

        for (const T &V : varr)
        {
            if (V == Target)
            {
                return true;
            }
        }

        return false;
    }
};

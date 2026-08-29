#pragma once
#include <iostream> // Include the iostream library for input/output operations
#include "../../include/Lib/clsCheck.h"   

 

    
     bool clsCheck::IsNumberInRange(short num, short from, short to)
     {
        return (num >= from && num <= to);
     }
     bool clsCheck::IsPrime(int Number)
    {
        int N = (int)round(Number / 2);

        for (int Counter = 2; Counter <= N; Counter++)
        {
            if (Number % Counter == 0)
                return false;
        }
        return true;
    }

     bool clsCheck::IsPerfectNumber(int Number)
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
     short clsCheck::FindPositionInArray(T arr[], int arrLength, T Target)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Target)
                return i;
        }

        return -1;
    }
    template <typename T>
     bool clsCheck::IsItemInArray(T arr[], T Item, int arrLength)
    {
        return FindPositionInArray(Item, arr, arrLength) != -1;
    }

    template <typename T>
     bool clsCheck::IsItemInVector(vector<T> varr, T Target)
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


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
    static bool IsNumberInRange(short num, short from, short to);
   

    static bool IsPrime(int Number);

    static bool IsPerfectNumber(int Number);

    template <typename T>
    static short FindPositionInArray(T arr[], int arrLength, T Target);

    template <typename T>
    static bool IsItemInArray(T arr[], T Item, int arrLength);

    template <typename T>
    static bool IsItemInVector(vector<T> varr, T Target);

};

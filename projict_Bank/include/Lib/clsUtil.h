#pragma once
#include <iostream> // Include the iostream library for input/output operations
#include <string>   // Include the string library to work with std::string
#include <vector>   // Include the vector library to use std::vector for dynamic arrays ReadNumberBetween
#include "clsCheck.h"
#include "clsInputValidate.h"


using namespace std;

class clsUtil
{

public:

    const double _PI = 3.14159265358979323846;
    
    static int ReverseNumber(int Number);

    static void ReadArray(int arr[], int& arrLength);

    static void ReadArray(string arr[], int& arrLength);

    enum enCharType
    {
        SamallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4,
        Mix = 5,
    };

    static void Srand();

    static int RandomNumber(int From, int To);

    static char GetRandomCharacter(enCharType CharType);
    static string GenerateWord(enCharType CharType, short Length);

    static string GenerateKey(int ContOfWord = 4, enCharType CharType = enCharType::Mix);

    static void GenerateKeys(string arr[], short NumberOfKeys, enCharType CharType = enCharType::Mix);
    static vector<string> GenerateKeys(short NumberOfKeys);


    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To);

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength);

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType);

    template <typename T>
    static void Swap(T& A, T& B);

    
    template <typename T>
    static void ShuffleArray(T arr[], int arrLength);

    template <typename T>
    static void ShuffleVector(vector<T>& varr);

    
    static string Taps(short Nember);

    static string EncryptText(string Text, short EncryptionKey);

    static string DecryptText(string Text, short EncryptionKey);

    static int SumArray(int arr[], int arrLength);

    static int SumVector(vector<int> arr);

    static short CalculateTotalPermissions(vector<short> Options);

    static vector<short> ConvertStringVectorToIntVector(vector<string> vStrings);


    
    template <typename T>
    static void PrintArray(T arr[], int arrLength);

    static int MaxNumber(int arr[], int arrLength);

    static int MinNumber(int arr[], int arrLength);

    static int MaxNumber(vector<int> vNumbers);

    static int MinNumber(vector<int> vNumbers);

    template <typename T>
    static void CopyArray(T arrSource[], T arrDestination[], int arrLength);


    static float MyABS(float Number);


    static string NumberToText(int Number);
};
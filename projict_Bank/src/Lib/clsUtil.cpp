#pragma once
#include <iostream> // Include the iostream library for input/output operations
#include <string>   // Include the string library to work with std::string
#include <vector>   // Include the vector library to use std::vector for dynamic arrays ReadNumberBetween
#include "../../include/Lib/clsCheck.h"
#include "../../include/Lib/clsInputValidate.h"
#include "../../include/Lib/clsUtil.h"


using namespace std;

 
     int clsUtil::ReverseNumber(int Number)
    {
        int Remainder = 0;
        int Number2 = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Number2 = Number2 * 10 + Remainder;
        }

        return Number2;
    }

     void clsUtil::ReadArray(int arr[], int& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;

        cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> arr[i];
        }
        cout << endl;
    }

     void clsUtil::ReadArray(string arr[], int& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;

        cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = clsInputValidate::ReadString("Element [" + to_string(i + 1) + "] : ");
        }
        cout << endl;
    }

    enum enCharType
    {
        SamallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4,
        Mix = 5,
    };

     void clsUtil::Srand()
    {
        // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

     int clsUtil::RandomNumber(int From, int To)
    {

        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

     char clsUtil::GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        case enCharType::Mix:
        {
            return char(RandomNumber(33, 122));
            break;
        }
        default:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
        return '\0';
    }

     string clsUtil::GenerateWord(enCharType CharType, short Length)
    {
        string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

     string clsUtil::GenerateKey(int ContOfWord , enCharType CharType )
    {
        string Key = "";

        Key = GenerateWord(CharType, ContOfWord) + "-";
        Key = Key + GenerateWord(CharType, ContOfWord) + "-";
        Key = Key + GenerateWord(CharType, ContOfWord) + "-";
        Key = Key + GenerateWord(CharType, ContOfWord);

        return Key;
    }

     void clsUtil::GenerateKeys(string arr[], short NumberOfKeys, enCharType CharType )
    {
        for (int i = 0; i < NumberOfKeys; i++)
        {
            arr[i] = GenerateKey(4, CharType);
        }
    }

     vector<string> clsUtil::GenerateKeys(short NumberOfKeys)
    {
        vector<string> keys;
        for (int i = 0; i < NumberOfKeys; i++)
        {
            keys.push_back(GenerateKey());
        }
        return keys;
    }

     void clsUtil::FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

     void clsUtil::FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);
    }

     void clsUtil::FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey();
    }

    
    template <typename T>
     void clsUtil::Swap(T& A, T& B)
    {
        T Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    
    template <typename T>
     void clsUtil::ShuffleArray(T arr[], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            Swap(arr[index1], arr[index2]);
        }
    }

    template <typename T>
     void clsUtil::ShuffleVector(vector<T>& varr)
    {
        int arrLength = varr.size();

        for (int i = 0; i < arrLength; i++)
        {
            int randomIndex = ReadRandomNumber(0, arrLength - 1);
            Swap(varr[randomIndex], varr[randomIndex]);
        }
    }


     string clsUtil::Taps(short Nember)
    {
        string tabs = "";
        for (int i = 1; i < Nember; i++)
        {
            tabs = tabs + "\t";
        }
        return tabs;
    }

     string clsUtil::EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

     string clsUtil::DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    int clsUtil::SumArray(int arr[], int arrLength)
    {
        int sum = 0; // Initialize sum to 0

        for (int i = 0; i < arrLength; i++)
        {
            sum += arr[i]; // Add each element of the array to sum
        }

        return sum; // Return the total sum of the array elements
    }
    int clsUtil::SumVector(vector<int> arr)
    {
        size_t arrLength = arr.size();

        int sum = 0; // Initialize sum to 0

        for (int i = 0; i < arrLength; i++)
        {
            sum += arr[i]; // Add each element of the array to sum
        }

        return sum; // Return the total sum of the array elements
    }

     short clsUtil::CalculateTotalPermissions(vector<short> Options) {

        short TotalPermission = 0;

        for (short Option : Options) {

            TotalPermission |= (1 << (Option - 1));

        }

        return TotalPermission;
    }
     vector<short> clsUtil::ConvertStringVectorToIntVector(vector<string> vStrings) {
        vector<short> vNumbers;
        for (string& S : vStrings) {
            // نتحقق أولاً أن النص ليس فارغاً لتجنب الأخطاء عند التحويل
            if (!S.empty()) {
                vNumbers.push_back(stoi(S)); // stoi تحول النص إلى رقم int
            }
        }
        return vNumbers;
    }



    template <typename T>
     void clsUtil::PrintArray(T arr[], int arrLength)
    {
        // Loop through the array and print each element followed by a space.
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << " ";

        cout << "\n"; // Print a newline after all elements are printed.
    }

     int clsUtil::MaxNumber(int arr[], int arrLength)
    {
        int Max = 0;
        for (int i = 1; i < arrLength; i++)
        {

            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;
    }

     int clsUtil::MinNumber(int arr[], int arrLength)
    {
        int Min = arr[0];
        for (int i = 1; i < arrLength; i++)
        {

            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;
    }
     int clsUtil::MaxNumber(vector<int> vNumbers)
    {
        int Max = vNumbers[0];
        for (int& N : vNumbers)
        {
            if (N > Max)
            {
                Max = N;
            }
        }
        return Max;
    }

     int clsUtil::MinNumber(vector<int> vNumbers)
    {
        int Min = vNumbers[0];

        for (int& N : vNumbers)
        {
            if (N < Min)
            {
                Min = N;
            }
        }

        return Min;
    }
    template <typename T>
     void clsUtil::CopyArray(T arrSource[], T arrDestination[], int arrLength)
    {
        for (T i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }

     float clsUtil::MyABS(float Number)
    {
        if (Number > 0)
            return Number;
        else
            return Number * -1;
    }


     string clsUtil::NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

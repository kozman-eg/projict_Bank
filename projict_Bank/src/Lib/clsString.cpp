#pragma once
#include <iostream> // Include the iostream library for input/output operations
#include <vector>   // Include the vector library to use std::vector for dynamic arrays ReadNumberBetween
#include "../../include/Lib/clsString.h"

using namespace std;

       clsString::clsString()
    {
       _Value = "";
    }

       clsString::clsString(string Value)
    {
        _Value = Value;
    }

    void clsString::SetValue(string Value) {
        _Value = Value;
    }

    string clsString::GetValue() {
        return _Value;
    }


   
     short clsString::Length(string S1)
    {
        return (short)S1.length();
    };

    short clsString::Length()
    {
        return (short)_Value.length();
    };

     short clsString::CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        size_t pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short clsString::CountWords()
    {
        return CountWords(_Value);
    };

     string  clsString::UpperFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  clsString::UpperFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

     string  clsString::LowerFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  clsString::LowerFirstLetterOfEachWord()
    {


        // no need to return value , this function will directly update the object value  
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

     string clsString::UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void clsString::UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

     string  clsString::LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void  clsString::LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

     char  clsString::InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

     string  clsString::InvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    void  clsString::InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(_Value);
    }


     short clsString::CountLetters(string S1, enWhatToCount WhatToCount )
    {


        if (WhatToCount == enWhatToCount::All)
        {
            return (short)S1.length();
        }

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;


            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;


        }

        return Counter;

    }

     short clsString::CountLetters(enWhatToCount WhatToCount)
    {
        return CountLetters(_Value, WhatToCount);
    }

     short clsString::CountCapitalLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  clsString::CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

     short clsString::CountSmallLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  clsString::CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

     short clsString::CountSpecificLetter(string S1, char Letter, bool MatchCase)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }

        }

        return Counter;
    }

    short  clsString::CountSpecificLetter(char Letter, bool MatchCase)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

     bool clsString::IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

    }

     short clsString::CountVowels(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (IsVowel(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  clsString::CountVowels()
    {
        return CountVowels(_Value);
    }

    vector<string> clsString::Split(string S1, string Delim)
    {

        vector<string> vString;

        size_t pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> clsString::Split(string Delim)
    {
        return Split(_Value, Delim);
    }

     string clsString::TrimLeft(string S1)
    {


        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void clsString::TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

     string clsString::TrimRight(string S1)
    {


        for (short i = (short)S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void clsString::TrimRight()
    {
        _Value = TrimRight(_Value);
    }

     string clsString::Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));

    }

    void clsString::Trim()
    {
        _Value = Trim(_Value);
    }

     string clsString::JoinString(vector<string> vString, string Delim)
    {

        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());


    }

     string clsString::JoinString(string arrString[], short Length, string Delim)
    {

        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());

    }

     string clsString::ReverseWordsInString(string S1)
    {

        vector<string> vString;
        string S2 = "";

        vString = Split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;

            S2 += *iter + " ";

        }

        S2 = S2.substr(0, S2.length() - 1); //remove last space.

        return S2;
    }

    void clsString::ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }


     string clsString::ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
    {
        size_t pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(),
                sRepalceTo);
            pos = S1.find(StringToReplace);//find next
        }
        return S1;
    }

     string clsString::ReplaceWord(string S1, string StringToReplace, string sRepalceTo, string Separator, bool MatchCase )
    {

        vector<string> vString = Split(S1, Separator);

        for (string& s : vString)
        {

            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }

            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s = sRepalceTo;
                }

            }

        }

        return JoinString(vString, Separator);
    }

    string clsString::ReplaceWord(string StringToReplace, string sRepalceTo, bool MatchCase )
    {
        return ReplaceWord(_Value, StringToReplace, sRepalceTo, " ", MatchCase);
    }

     string clsString::RemovePunctuations(string S1)
 {

     string S2 = "";

     for (short i = 0; i < S1.length(); i++)
     {
         if (!ispunct(S1[i]))
         {
             S2 += S1[i];
         }
     }

     return S2;

 }

   void clsString::RemovePunctuations()
 {
     _Value = RemovePunctuations(_Value);
 }




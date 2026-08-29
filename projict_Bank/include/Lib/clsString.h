#pragma once
#include <iostream> // Include the iostream library for input/output operations
#include <vector>   // Include the vector library to use std::vector for dynamic arrays ReadNumberBetween


using namespace std;

class clsString 
{

private:
    string _Value;

public:

    clsString();

    clsString(string Value);

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };


    void SetValue(string Value);
    string GetValue();
    __declspec(property(get = GetValue, put = SetValue)) string Value;

   
    static short Length(string S1);
    short Length();

    static short CountWords(string S1);
    short CountWords();

    static string  UpperFirstLetterOfEachWord(string S1);
    void  UpperFirstLetterOfEachWord();

    static string  LowerFirstLetterOfEachWord(string S1);
    void  LowerFirstLetterOfEachWord();
    
    static string UpperAllString(string S1);
    void UpperAllString();

    static string LowerAllString(string S1);
    void LowerAllString();

    static char  InvertLetterCase(char char1);

    static string InvertAllLettersCase(string S1);
    void InvertAllLettersCase();


   static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All);
   short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All);
  
   static short  CountCapitalLetters(string S1);
   short  CountCapitalLetters();

   static short  CountSmallLetters(string S1);
   short  CountSmallLetters();
   
   static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true);
   short  CountSpecificLetter(char Letter, bool MatchCase = true);

   static bool IsVowel(char Ch1);

   static short CountVowels(string S1);
   short CountVowels();

   static vector<string> Split(string S1, string Delim);
   vector<string> Split(string Delim);

   static string TrimLeft(string S1);
   void TrimLeft();

   static string TrimRight(string S1);
   void TrimRight();

   static string Trim(string S1);
   void Trim();

   static string JoinString(vector<string> vString, string Delim);
   static string JoinString(string arrString[], short Length, string Delim);

   static string ReverseWordsInString(string S1);
   void ReverseWordsInString();


   static string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo);

   static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, string Separator = " ", bool MatchCase = true);
   string ReplaceWord(string StringToReplace, string sRepalceTo, bool MatchCase = true);

   static string RemovePunctuations(string S1);
   void RemovePunctuations();


};


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "src/Lib/clsDate.h"
#include "src/Lib/clsUtil.h"
#include "src/Lib/clsInputValidate.h"

using namespace std;

int main()
{
    clsUtil::Srand();

    vector<string> ietm = {"as", "asdd"};
    vector<int> number = {1, 2};

    cout << clsCheck::IsItemInVector<string>(ietm, "kk");
    cout << clsCheck::IsItemInVector(number, 3);
    cout << "_____________________________________________";

    cout << clsUtil::RandomNumber(1, 10) << endl;

    string arr1[3];

    clsUtil::GetRandomCharacter(clsUtil::CapitalLetter);
    cout << clsUtil::GenerateWord(clsUtil::Mix, 8) << endl;
    cout << clsUtil::GenerateKey(clsUtil::Mix) << endl;

    clsUtil::GenerateKeys(arr1, 3, clsUtil::Mix);

    clsUtil::PrintArray(arr1, 3);
    cout << "________________________" << endl;

    // Swap Int
    int x = 10, y = 20;
    cout << x << " " << y << endl;
    clsUtil::Swap(x, y);
    cout << x << " " << y << endl
         << endl;

    // Swap double
    double a = 10.5, b = 20.5;
    cout << a << " " << b << endl;
    clsUtil::Swap(a, b);
    cout << a << " " << b << endl
         << endl;

    // Swap String
    string s1 = "Ali", s2 = "Ahmed";
    cout << s1 << " " << s2 << endl;
    clsUtil::Swap(s1, s2);
    cout << s1 << " " << s2 << endl
         << endl;

    // Swap Dates
    clsDate d1(1, 10, 2022), d2(1, 1, 2022);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;
    clsUtil::Swap(d1, d2);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;

    // Shuffl Array

    // int array
    int Arr1[5] = {1, 2, 3, 4, 5};
    clsUtil::ShuffleArray(Arr1, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr1[i] << endl;
    }

    // string array
    string Arr2[5] = {"Ali", "Fadi", "Ahmed", "Qasem", "Khalid"};
    clsUtil::ShuffleArray(Arr2, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr2[i] << endl;
    }

    int Arr3[5];
    clsUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr3[i] << endl;
    }

    string Arr4[5];
    clsUtil::FillArrayWithRandomWords(Arr4, 5, clsUtil::Mix, 8);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr4[i] << endl;
    }

    string Arr5[5];
    clsUtil::FillArrayWithRandomKeys(Arr5, 5, clsUtil::Mix);
    cout << "\nArray after filling keys:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr5[i] << endl;
    }

    cout << "\nText1 " << clsUtil::Taps(5) << "Text2\n";

    const short EncryptionKey = 2; // this is the key.

    string TextAfterEncryption, TextAfterDecryption;
    string Text = "Mohammed Abu-Hadhoud";
    TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
    TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption : ";
    cout << Text << endl;
    cout << "Text After Encryption  : ";
    cout << TextAfterEncryption << endl;
    cout << "Text After Decryption  : ";
    cout << TextAfterDecryption << endl;

    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),clsDate(8, 12, 2022),clsDate(31, 12, 2022))
         << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),clsDate(31, 12, 2022),clsDate(8, 12, 2022))
         << endl;

    cout << "\nPlease Enter a Number:\n";
    int xx = clsInputValidate::ReadNumber<int>("Invalid Number, Enter again:\n");
    cout << "x=" << xx;

    cout << "\nPlease Enter a Number between 1 and 5:\n";
    int yy = clsInputValidate::ReadNumberBetween<int>(1, 5, "Number is not within range, enter again:\n");
    cout << "y=" << yy;

    cout << "\nPlease Enter a Double Number:\n";
    double aa = clsInputValidate::ReadNumber<double>("Invalid Number, Enter again:\n");
    cout << "a=" << aa;

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    double bb = clsInputValidate::ReadNumberBetween<double>(1, 5, "Number is not within range, enter again:\n");
    cout << "b=" << bb;

    cout << endl
         << clsInputValidate::IsValideDate(clsDate(35, 12, 2022)) << endl;

    system("pause>0");

    return 0;
}

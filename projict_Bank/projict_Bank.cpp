// projict_Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include "Global.h"
#include "src/Screen/clsLoginScreen.h"


using namespace std;


int main()

{
    while (clsLoginScreen::ShowLoginScreen());

    system("pause>0");
    return 0;
}


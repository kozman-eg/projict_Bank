#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"

class clsTransferScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client);

    static string _ReadAccountNumber();

    static  double ReadAmount(clsBankClient SourceClient);

public:

    static void ShowTransferScreen();

};


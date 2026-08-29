#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"

class clsClientListScreen :protected clsScreen
{

private:
    static void PrintClientRecordLine(clsBankClient Client);

public:


    static void ShowClientsList() ;

};

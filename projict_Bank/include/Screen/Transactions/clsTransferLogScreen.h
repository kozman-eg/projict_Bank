#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"


class clsTransferLogScreen :protected clsScreen
{

private:

    static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord);

public:

    static void ShowTransferLogScreen();

};

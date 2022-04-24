#ifndef PIN_DLL_H
#define PIN_DLL_H

#include "Pin_Dll_global.h"
#include "dialogpin.h"

class Pin_Dll
{

public:
    void PIN_DLL_EXPORT openDllDialog();
    QString PIN_DLL_EXPORT returnFromDll();
private:
    DialogPin *objectDialogPin;
    QString dllValue;
};

#endif // PIN_DLL_H

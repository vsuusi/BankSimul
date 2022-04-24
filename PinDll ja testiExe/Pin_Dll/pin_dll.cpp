#include "pin_dll.h"




void Pin_Dll::openDllDialog()
{
    objectDialogPin=new DialogPin;
    objectDialogPin->exec();
    dllValue=objectDialogPin->getDialogPinValue();
    delete objectDialogPin;
}

QString Pin_Dll::returnFromDll()
{
    return dllValue;
    qDebug() <<dllValue;

}

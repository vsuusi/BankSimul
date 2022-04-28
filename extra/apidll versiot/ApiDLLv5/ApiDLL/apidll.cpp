#include "apidll.h"


void ApiDLL::saaToken()
{
    pLogin=new login();
    tokenValue=pLogin->getToken();
    delete pLogin;
}

QByteArray ApiDLL::returnFromLogin()
{
    return tokenValue;
}

void ApiDLL::saaPinJaKortti()
{
    pLogin=new login;
    pinValue=pLogin->getKorttinumero();
    korttiValue=pLogin->getPin();
    delete pLogin;
}

QString ApiDLL::return2FromLogin()
{
    return korttiValue;
    return pinValue;
}

void ApiDLL::saaTili()
{
    pTili=new Tili;
    tiliValue=pTili->getRaTili();
    delete pTili;
}

QString ApiDLL::returnFromTili()
{
    return tiliValue;
}



void ApiDLL::saaTili_Asiakas()
{
    pTili_Asiakas=new tili_asiakas;
    tili_aValue=pTili_Asiakas->getRaTili_Asiakas();
    delete pTili_Asiakas;
}

QString ApiDLL::returnFromTili_Asiakas()
{
    return tili_aValue;
}

void ApiDLL::saaAasi()
{
    pAsiakas = new asiakas;
    asiakasValue=pAsiakas->getAasi();
    delete pAsiakas;

}

QString ApiDLL::returnFromAsiakas()
{
    return asiakasValue;
}

void ApiDLL::saaKortti()
{
    pKortti = new kortti;
    RaKorttiValue=pKortti->getRaKortti();
    delete pKortti;
}

QString ApiDLL::returnFromKortti()
{
    return RaKorttiValue;
}

void ApiDLL::saaTiliTapahtumat()
{
    pTilitapahtumat=new tilitapahtumat;
    tiliTapahtumaValue=pTilitapahtumat->getRaTilitapahtumat();
    delete pTilitapahtumat;
}

QString ApiDLL::returnFromTiliTapahtumat()
{
    return tiliTapahtumaValue;
}










QT       += core gui
QT +=network
QT +=serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    kayttoliittyma.cpp \
    main.cpp \
    mainwindow.cpp \
    nostoikkuna.cpp \
    pininterface.cpp \
    tapahtumavirta.cpp

HEADERS += \
    kayttoliittyma.h \
    mainwindow.h \
    nostoikkuna.h \
    pininterface.h \
    tapahtumavirta.h

FORMS += \
    kayttoliittyma.ui \
    mainwindow.ui \
    nostoikkuna.ui \
    pininterface.ui \
    tapahtumavirta.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32: LIBS += -L$$PWD/'../Lukija_Dll ja testiEexe/Lukija_Dll/build/debug/' -lLukija_Dll

INCLUDEPATH += $$PWD/'../Lukija_Dll ja testiEexe/Lukija_Dll'
DEPENDPATH += $$PWD/'../Lukija_Dll ja testiEexe/Lukija_Dll'

#santeri versio
win32: LIBS += -L$$PWD/../ApiDLL/build/debug/ -lApiDLL

INCLUDEPATH += $$PWD/../ApiDLL
DEPENDPATH += $$PWD/../ApiDLL

#janneversio
#win32: LIBS += -L$$PWD/'../apidll versiot/ApiDLLv6/ApiDLL/build/debug/' -lApiDLL

#INCLUDEPATH += $$PWD/'../apidll versiot/ApiDLLv6/ApiDLL'
#DEPENDPATH += $$PWD/'../apidll versiot/ApiDLLv6/ApiDLL'


win32: LIBS += -L$$PWD/'../PinDll ja testiExe/Pin_Dll/build/debug/' -lPin_Dll

INCLUDEPATH += $$PWD/'../PinDll ja testiExe/Pin_Dll'
DEPENDPATH += $$PWD/'../PinDll ja testiExe/Pin_Dll'

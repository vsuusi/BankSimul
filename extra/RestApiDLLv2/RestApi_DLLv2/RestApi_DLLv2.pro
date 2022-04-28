QT -= gui
QT += network

TEMPLATE = lib
DEFINES += RESTAPI_DLLV2_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    asiakas.cpp \
    kortti.cpp \
    login.cpp \
    restapi_dllv2.cpp \
    tili.cpp \
    tili_asiakas.cpp \
    tilitapahtumat.cpp

HEADERS += \
    RestApi_DLLv2_global.h \
    asiakas.h \
    kortti.h \
    login.h \
    restapi_dllv2.h \
    tili.h \
    tili_asiakas.h \
    tilitapahtumat.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

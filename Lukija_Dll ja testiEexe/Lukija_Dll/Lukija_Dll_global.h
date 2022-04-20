#ifndef LUKIJA_DLL_GLOBAL_H
#define LUKIJA_DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LUKIJA_DLL_LIBRARY)
#  define LUKIJA_DLL_EXPORT Q_DECL_EXPORT
#else
#  define LUKIJA_DLL_EXPORT Q_DECL_IMPORT
#endif

#endif // LUKIJA_DLL_GLOBAL_H

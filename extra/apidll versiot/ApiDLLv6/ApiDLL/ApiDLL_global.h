#ifndef APIDLL_GLOBAL_H
#define APIDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(APIDLL_LIBRARY)
#  define APIDLL_EXPORT Q_DECL_EXPORT
#else
#  define APIDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // APIDLL_GLOBAL_H

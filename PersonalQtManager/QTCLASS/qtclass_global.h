#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTCLASS_LIB)
#  define QTCLASS_EXPORT Q_DECL_EXPORT
# else
#  define QTCLASS_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTCLASS_EXPORT
#endif

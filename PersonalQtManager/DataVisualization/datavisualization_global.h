#pragma once
#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DataVisualization_LIB)
#  define DataVisualization_EXPORT Q_DECL_EXPORT
# else
#  define DataVisualization_EXPORT Q_DECL_IMPORT
# endif
#else
# define DataVisualization_EXPORT
#endif
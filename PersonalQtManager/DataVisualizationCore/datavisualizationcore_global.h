#pragma once

#include <QtCore/qglobal.h>

//#ifndef BUILD_STATIC
//# if defined(DATAVISUALIZATIONCORE_LIB)
//#  define DATAVISUALIZATIONCORE_EXPORT Q_DECL_EXPORT
//# else
//#  define DATAVISUALIZATIONCORE_EXPORT Q_DECL_IMPORT
//# endif
//#else
//# define DATAVISUALIZATIONCORE_TEMPLATE
//#endif
#ifndef BUILD_STATIC
# if defined(DATAVISUALIZATIONCORE_LIB)
#  define DATAVISUALIZATIONCORE_TEMPLATE Q_DECL_EXPORT
# else
#  define DATAVISUALIZATIONCORE_TEMPLATE Q_DECL_IMPORT
# endif
#else
# define DATAVISUALIZATIONCORE_TEMPLATE
#endif
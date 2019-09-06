#ifndef PROJECTIONP_H
#define PROJECTIONP_H

#define SIZE_SCREEN 300
#define OFFSET 0

#include "node.h"

// set coordinates to zero belonging one of axis for parallel projection
int projectionP();

// parallel projection at YZ
typeError projectPX(nodeType* nodes, const unsigned int size);

// parallel projection at ZX
typeError projectPY(nodeType* nodes, const unsigned int size);

// parallel projection at XY
typeError projectPZ(nodeType* nodes, const unsigned int size);

// set coordinates to zero belonging one of axis for central projection
double projectCAxis();

// set coordinates by distance for central projection
double projectC(const double coord, const double axis, const double distance);

// central projection with viewer at axis X
typeError projectCX(nodeType* nodes, const unsigned int size, const double d);

// central projection with viewer at axis Y
typeError projectCY(nodeType* nodes, const unsigned int size, const double d);

// central projection with viewer at axis Z
typeError projectCZ(nodeType* nodes, const unsigned int size, const double d);

#endif // PROJECTIONP_H


#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "errors.h"
#include "node.h"
#include "modeldatawork.h"

#include <math.h>

struct tmpTurnDataType
{
    double pr1, pr2;
    double c1, c2;
    double angle;
};

// from shift matrix
double shift(const double coord, const double offset);

// from scale matrix
double scale(const double coord, const double coeff, const double center);

// translate degree to radians
double degToRad(const int angle);

// from turn matrix for first coordinate
double turnFirstCoord(const tmpTurnDataType data);

// from turn matrix for second coordinate
double turnSecondCoord(const tmpTurnDataType data);

// turn model at X
typeError turnX(nodeType* nodes, const turnDataType turnData, const unsigned int size);

// turn model at Y
typeError turnY(nodeType* nodes, const turnDataType turnData, const unsigned int size);

// turn model at Z
typeError turnZ(nodeType* nodes, const turnDataType turnData, const unsigned int size);

#endif // TRANSFORMATIONS_H


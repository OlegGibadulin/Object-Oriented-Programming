#ifndef DISPLAYWORK_CPP
#define DISPLAYWORK_CPP

#include "displaywork.h"

double getX(double x, double z)
{
    return x + z * Z_COEFF;
}

double getY(double y, double z)
{
    return -y - z * Z_COEFF;
}

#endif // DISPLAYWORK_CPP


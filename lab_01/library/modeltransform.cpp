#ifndef MODELTRANSFORM_CPP
#define MODELTRANSFORM_CPP

#include "modeltransform.h"

typeError modelShift(nodeType* nodes, const shiftDataType shiftData, \
                     const unsigned int size)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].x = shift(nodes[i].x, shiftData.dx);
        nodes[i].y = shift(nodes[i].y, shiftData.dy);
        nodes[i].z = shift(nodes[i].z, shiftData.dz);
    }

    return OK;
}

typeError modelScale(nodeType* nodes, const scaleDataType scaleData, \
                     const unsigned int size)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].x = scale(nodes[i].x, scaleData.kx, scaleData.cx);
        nodes[i].y = scale(nodes[i].y, scaleData.ky, scaleData.cy);
        nodes[i].z = scale(nodes[i].z, scaleData.kz, scaleData.cz);
    }

    return OK;
}

typeError modelTurn(nodeType* nodes, const turnDataType turnData, \
                    const unsigned int size)
{
    typeError error;

    switch (turnData.axis)
    {
        case (X):
            error = turnX(nodes, turnData, size);
            break;
        case (Y):
            error = turnY(nodes, turnData, size);
            break;
        case (Z):
            error = turnZ(nodes, turnData, size);
            break;
        default:
            error = ErrorField;
    }

    return error;
}

#endif // MODELTRANSFORM_CPP


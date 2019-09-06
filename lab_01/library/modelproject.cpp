#ifndef MODELPROJECT_CPP
#define MODELPROJECT_CPP

#include "modelproject.h"

typeError modelProjectP(nodeType* nodes, const projectPDataType projectPData, \
                     const unsigned int size)
{
    typeError error;

    switch (projectPData.axis)
    {
        case X:
            error = projectPX(nodes, size);
            break;
        case Y:
            error = projectPY(nodes, size);
            break;
        case Z:
            error = projectPZ(nodes, size);
            break;
        default:
            error = ErrorField;
    }

    return error;
}

typeError modelProjectC(nodeType* nodes, const projectCDataType projectCData, \
                     const unsigned int size)
{
    typeError error;

    switch (projectCData.axis)
    {
        case X:
            error = projectCX(nodes, size, projectCData.distanse);
            break;
        case Y:
            error = projectCY(nodes, size, projectCData.distanse);
            break;
        case Z:
            error = projectCZ(nodes, size, projectCData.distanse);
            break;
        default:
            error = ErrorField;
    }

    return error;
}

#endif // MODELPROJECT_CPP


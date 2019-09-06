#ifndef PARALLPROJECTION_CPP
#define PARALLPROJECTION_CPP

#include "projections.h"

int projectionP()
{
    return 0;
}

typeError projectPX(nodeType* nodes, const unsigned int size)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
        nodes[i].x = projectionP();

    return OK;
}

typeError projectPY(nodeType* nodes, const unsigned int size)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
        nodes[i].y = projectionP();

    return OK;
}

typeError projectPZ(nodeType* nodes, const unsigned int size)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
        nodes[i].z = projectionP();

    return OK;
}

double projectCAxis()
{
    return 0;
}

double projectC(const double coord, const double axis, const double distance)
{
    return coord / (axis / distance + 1);
}

typeError projectCX(nodeType* nodes, const unsigned int size, const double d)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].x = projectC(nodes[i].x, nodes[i].z, d);
        nodes[i].y = projectC(nodes[i].y, nodes[i].z, d);
        nodes[i].z = projectCAxis();
    }

    return OK;
}

typeError projectCY(nodeType* nodes, const unsigned int size, const double d)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].y = projectC(nodes[i].y, nodes[i].x, d);
        nodes[i].z = projectC(nodes[i].z, nodes[i].x, d);
        nodes[i].x = projectCAxis();
    }

    return OK;
}

typeError projectCZ(nodeType* nodes, const unsigned int size, const double d)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].z = projectC(nodes[i].z, nodes[i].y, d);
        nodes[i].x = projectC(nodes[i].x, nodes[i].y, d);
        nodes[i].y = projectCAxis();
    }

    return OK;
}

#endif // PARALLPROJECTION_CPP


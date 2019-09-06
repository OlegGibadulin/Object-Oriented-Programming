#ifndef EDGE_CPP
#define EDGE_CPP

#include "edge.h"

bool edgesIsExist(const edgeType* edges)
{
    return edges ? true : false;
}

typeError checkEdgesExist(const edgeType* edges)
{
    return edgesIsExist(edges) ? OK : ErrorEdgesExist;
}

typeError edgesAllocation(edgeType*& edges, const unsigned int size)
{
    if (edges != NULL && edgesFree(edges))
        return ErrorFree;

    edges = new edgeType[size];

    return edgesIsExist(edges) ? OK : ErrorAllocation;
}

typeError edgesFree(edgeType*& edges)
{
    if (edgesIsExist(edges))
        delete [] edges;

    return OK;
}

typeError edgeLoad(unsigned int& edgeSrc, unsigned int& edgePurp, fileWorkType file)
{
    typeError error;

    if ((error = getEdgeData(edgeSrc, file.f)))
        return error;

    return getEdgeData(edgePurp, file.f);
}

typeError edgeSave(fileWorkType file, const unsigned int edgeSrc, const unsigned int edgePurp)
{
    typeError error;

    if ((error = setEdgeData(file.f, edgeSrc)))
        return error;

    return setEdgeData(file.f, edgePurp);
}

typeError edgesLoad(edgeType* edges, fileWorkType file, const unsigned int size)
{
    typeError error;

    if ((error = checkEdgesExist(edges)))
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = edgeLoad(edges[i].src, edges[i].purp, file);

    return error;
}

typeError edgesSave(const edgeType* edges, fileWorkType file, const unsigned int size)
{
    typeError error;

    if ((error = checkEdgesExist(edges)))
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = edgeSave(file, edges[i].src, edges[i].purp);

    return error;
}

#endif // EDGE_CPP


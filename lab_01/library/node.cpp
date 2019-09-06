#ifndef NODE_CPP
#define NODE_CPP

#include "node.h"

bool nodesIsExist(const nodeType* nodes)
{
    return nodes ? true : false;
}

typeError checkNodesExist(const nodeType* nodes)
{
    return nodesIsExist(nodes) ? OK : ErrorNodesExist;
}

typeError nodesAllocation(nodeType*& nodes, const unsigned int size)
{
    if (nodes != NULL && nodesFree(nodes))
        return ErrorFree;

    nodes = new nodeType[size];

    return nodesIsExist(nodes) ? OK : ErrorAllocation;
}

typeError nodesFree(nodeType*& nodes)
{
    if (nodesIsExist(nodes))
        delete [] nodes;

    return OK;
}

typeError nodeLoad(double& nodeX, double& nodeY, double& nodeZ, fileWorkType file)
{
    typeError error;

    if ((error = getNodeData(nodeX, file.f)))
        return error;

    if ((error = getNodeData(nodeY, file.f)))
        return error;

    return getNodeData(nodeZ, file.f);
}

typeError nodeSave(FILE* f, const double nodeX, const double nodeY, const double nodeZ)
{
    typeError error;

    if ((error = setNodeData(f, nodeX)))
        return error;

    if ((error = setNodeData(f, nodeY)))
        return error;

    return setNodeData(f, nodeZ);
}

typeError nodesLoad(nodeType* nodes, fileWorkType file, const unsigned int size)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = nodeLoad(nodes[i].x, nodes[i].y, nodes[i].z, file);

    return error;
}

typeError nodesSave(const nodeType* nodes, fileWorkType file, const unsigned int size)
{
    typeError error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = nodeSave(file.f, nodes[i].x, nodes[i].y, nodes[i].z);

    return error;
}

#endif // NODE_CPP


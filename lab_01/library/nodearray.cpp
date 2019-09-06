#ifndef NODEARR_CPP
#define NODEARR_CPP

#include "nodearray.h"

typeError nodeArrInit(nodeArrType& nodeArr)
{
    nodeArr.nodes = NULL;
    nodeArr.size = 0;

    return OK;
}

typeError nodeArrFree(nodeArrType& nodeArr)
{
    typeError error;

    if ((error = nodesFree(nodeArr.nodes)))
        return error;

    return (error = nodeArrInit(nodeArr)) ? error : OK;
}

typeError nodesArrLoad(nodeArrType& nodeArr, fileWorkType file)
{
    typeError error;

    if ((error = isCorrectFile(file.f)))
        return error;

    if ((error = getSize(nodeArr.size, file.f)))
        return error;

    if ((error = nodesAllocation(nodeArr.nodes, nodeArr.size)))
        return error;

    return nodesLoad(nodeArr.nodes, file, nodeArr.size);
}

typeError nodesArrSave(fileWorkType file, const nodeArrType nodeArr)
{
    typeError error;

    if ((error = checkFileForOpen(file.f)))
        return error;

    if ((error = checkNodesExist(nodeArr.nodes)))
        return error;

    if ((error = setSize(file.f, nodeArr.size)))
        return error;

    return nodesSave(nodeArr.nodes, file, nodeArr.size);
}

#endif // NODEARR_CPP


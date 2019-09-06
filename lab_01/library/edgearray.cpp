#ifndef EDGEARR_CPP
#define EDGEARR_CPP

#include "edgearray.h"

typeError edgeArrInit(edgeArrType& edgeArr)
{
    edgeArr.edges = NULL; //nullptr
    edgeArr.size = 0;

    return OK;
}

typeError edgeArrFree(edgeArrType& edgeArr)
{
    typeError error;

    if ((error = edgesFree(edgeArr.edges)))
        return error;

    return (error = edgeArrInit(edgeArr)) ? error : OK;
}

typeError edgesArrLoad(edgeArrType& edgeArr, fileWorkType file)
{
    typeError error;

    if ((error = isCorrectFile(file.f)))
        return error;

    if ((error = getSize(edgeArr.size, file.f)))
        return error;

    if ((error = edgesAllocation(edgeArr.edges, edgeArr.size)))
        return error;

    if ((error = edgesLoad(edgeArr.edges, file, edgeArr.size)))
       edgesFree(edgeArr.edges);

    return error;
}

typeError edgesArrSave(fileWorkType file, const edgeArrType edgeArr)
{
    typeError error;

    if ((error = checkFileForOpen(file.f)))
        return error;

    if ((error = checkEdgesExist(edgeArr.edges)))
        return error;

    if ((error = setSize(file.f, edgeArr.size)))
        return error;

    return edgesSave(edgeArr.edges, file, edgeArr.size);
}

#endif // EDGEARR_CPP


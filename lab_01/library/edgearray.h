#ifndef EDGEARR_H
#define EDGEARR_H

#include "errors.h"
#include "edge.h"
#include "filework.h"

#include <stdio.h>

// type of array of edges
struct edgeArrType
{
    edgeType* edges;
    unsigned int size;
};

// initialization of array of edges
typeError edgeArrInit(edgeArrType& edgeArr);

// free array of edges
typeError edgeArrFree(edgeArrType& edgeArr);

// load edges array
typeError edgesArrLoad(edgeArrType& edgeArr, fileWorkType file);

// save edges array
typeError edgesArrSave(fileWorkType file, const edgeArrType edgeArr);

#endif // EDGEARR_H


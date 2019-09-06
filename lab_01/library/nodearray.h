#ifndef NODEARR_H
#define NODEARR_H

#include "errors.h"
#include "node.h"
#include "filework.h"

#include <stdio.h>

#define READ_OK 1
#define WRITE_OK 1

struct nodeArrType
{
    nodeType* nodes;
    unsigned int size;
};

// initialization of array of node
typeError nodeArrInit(nodeArrType &nodeArr);

// free of array of node
typeError nodeArrFree(nodeArrType& nodeArr);

// load data of nodes
typeError nodesArrLoad(nodeArrType& nodeArr, fileWorkType file);

// save data of nodes
typeError nodesArrSave(fileWorkType file, const nodeArrType nodeArr);

#endif // NODEARR_H


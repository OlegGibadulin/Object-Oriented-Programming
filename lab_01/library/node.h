#ifndef NODE_H
#define NODE_H

#include "errors.h"
#include "filework.h"

#include <stdio.h>

// type of node of model
struct nodeType
{
    double x;
    double y;
    double z;
};

// type of field of node
enum nodeFieldType
{
    fieldX,
    fieldY,
    fieldZ
};

// check for existing array of nodes
bool nodesIsExist(const nodeType *nodes);

// check for existing array of nodes
typeError checkNodesExist(const nodeType* nodes);

// allocation memory for array of nodes
typeError nodesAllocation(nodeType*& nodes, const unsigned int size);

// free memory for array of nodes
typeError nodesFree(nodeType*& nodes);

// read data of node
typeError nodeLoad(double& nodeX, double& nodeY, double& nodeZ, fileWorkType file);

// write data of node
typeError nodeSave(FILE* f, const double nodeX, const double nodeY, const double nodeZ);

// read data of nodes
typeError nodesLoad(nodeType *nodes, fileWorkType file, const unsigned int size);

// write data of nodes
typeError nodesSave(const nodeType* nodes, fileWorkType file, const unsigned int size);

#endif // NODE_H


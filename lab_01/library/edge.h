#ifndef EDGE_H
#define EDGE_H

#include "errors.h"
#include "filework.h"

#include <stdio.h>

// type of edge connecting nodes
struct edgeType
{
    unsigned int src;
    unsigned int purp;
};

// check for existing of array of edges
bool edgesIsExist(const edgeType *edges);

// check for existing of array of edges
typeError checkEdgesExist(const edgeType* edges);

// allocation memory for array of edges
typeError edgesAllocation(edgeType*& edges, const unsigned int size);

// free memory for array of edges
typeError edgesFree(edgeType*& edges);

// read data of edge from file
typeError edgeLoad(unsigned int& edgeSrc, unsigned int& edgePurp, FILE* f);

// save data of edge to file
typeError edgeSave(fileWorkType file, const unsigned int edgeSrc, const unsigned int edgePurp);

// read data of edges from file
typeError edgesLoad(edgeType* edges, fileWorkType file, const unsigned int size);

// save data of edges to file
typeError edgesSave(const edgeType* edges, fileWorkType file, const unsigned int size);

#endif // EDGE_H


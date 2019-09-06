#ifndef MODELPROJECT_H
#define MODELPROJECT_H

#include "errors.h"
#include "modeldatawork.h"
#include "node.h"
#include "projections.h"

// change coordinates of nodes for executing of parallel projection
typeError modelProjectP(nodeType *nodes, const struct projectPDataType \
                        projectPData, const unsigned int size);

// change coordinates of nodes for executing of central projection
typeError modelProjectC(nodeType* nodes, const struct projectCDataType \
                        projectCData, const unsigned int size);

#endif // MODELPROJECT_H


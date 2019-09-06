#ifndef MODELTRANSFORM_H
#define MODELTRANSFORM_H

#include "errors.h"
#include "modeldatawork.h"
#include "node.h"
#include "transformations.h"

// change coordinates of nodes for shift
typeError modelShift(nodeType *nodes, const struct shiftDataType shiftData, \
                     const unsigned int size);

// change coordinates of nodes for scale
typeError modelScale(nodeType *nodes, const struct scaleDataType scaleData, \
                     const unsigned int size);

// change coordinates of nodes for turn
typeError modelTurn(nodeType *nodes, const struct turnDataType turnData, \
                     const unsigned int size);

#endif // MODELTRANSFORM_H


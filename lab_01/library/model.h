#ifndef MODEL_H
#define MODEL_H

#include "errors.h"
#include "edgearray.h"
#include "nodearray.h"

// type for model (frame)
struct modelType
{
    edgeArrType edgeArr;
    nodeArrType nodeArr;
};

// initialize model
modelType modelInit();

// free model data
typeError modelFree(modelType& model);

// create new model
typeError modelChange(modelType& model, modelType& tmpModel);

#endif // MODEL_H


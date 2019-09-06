#ifndef MODEL_CPP
#define MODEL_CPP

#include "model.h"

modelType modelInit()
{
    modelType model;
    edgeArrInit(model.edgeArr);
    nodeArrInit(model.nodeArr);

    return model;
}

typeError modelFree(modelType& model)
{
    if (edgeArrFree(model.edgeArr))
        return ErrorFree;

    return nodeArrFree(model.nodeArr) ? ErrorFree : OK;
}

typeError modelChange(modelType& model, modelType& tmpModel)
{
    typeError error;

    if ((error = modelFree(model)))
        return error;

    model = tmpModel;

    return OK;
}

#endif // MODEL_CPP


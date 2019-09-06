#ifndef MODELFILEWORK_CPP
#define MODELFILEWORK_CPP

#include "modelfilework.h"

typeError modelLoad(modelType& model, fileWorkType file)
{
    modelType tmpModel = modelInit();

    typeError error;

    if ((error = edgesArrLoad(tmpModel.edgeArr, file)))
        return error;

    if ((error = nodesArrLoad(tmpModel.nodeArr, file)))
    {
        edgeArrFree(tmpModel.edgeArr);
        return error;
    }

    if ((error = modelChange(model, tmpModel)))
    {
        edgeArrFree(tmpModel.edgeArr);
        nodeArrFree(tmpModel.nodeArr);
    }

    return error;
}

typeError modelSave(const modelType model, fileWorkType file)
{
    typeError error;

    if ((error = edgesArrSave(file, model.edgeArr)))
        return error;

    return nodesArrSave(file, model.nodeArr);
}

#endif // MODELFILEWORK_CPP


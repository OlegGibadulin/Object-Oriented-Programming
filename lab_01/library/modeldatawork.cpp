#ifndef MODELDATAWORK_CPP
#define MODELDATAWORK_CPP

#include "modeldatawork.h"

typeError modelLoadData(modelType& model, const actionDataType data)
{
    const char* fileName = data.fileName;

    typeError error;
    if ((error = isFileNameEmpty(fileName)))
        return error;

    fileWorkType file;
    if ((error = fileTypeInit(file)))
        return error;

    if ((error = openFileForRead(file, fileName)))
        return error;

    error = modelLoad(model, file);

    if (isOpenFile(file.f))
        fclose(file.f);

    return error;
}

typeError modelSaveData(const modelType model, const actionDataType data)
{
    const char* fileName = data.fileName;

    typeError error;
    if ((error = isFileNameEmpty(fileName)))
        return error;

    fileWorkType file;
    if ((error = fileTypeInit(file)))
        return error;

    if ((error = openFileForWrite(file, fileName)))
        return error;

    error = modelSave(model, file);

    if (isOpenFile(file.f))
        fclose(file.f);

    return error;
}

typeError modelShiftData(const modelType &model, const actionDataType data)
{
    return modelShiftParam(model.nodeArr, data.param);
}

typeError modelScaleData(const modelType &model, const actionDataType data)
{
    return modelScaleParam(model.nodeArr, data.param);
}

typeError modelTurnData(const modelType &model, const actionDataType data)
{
    return modelTurnParam(model.nodeArr, data.param);
}

typeError modelProjectPData(const modelType &model, const actionDataType data)
{
    return modelProjectPParam(model.nodeArr, data.param);
}

typeError modelProjectCData(const modelType &model, const actionDataType data)
{
    return modelProjectCParam(model.nodeArr, data.param);
}

typeError modelDrawData(const modelType model)
{
    return modelDrawParam(model.edgeArr, model.nodeArr);
}

#endif // MODELDATAWORK_CPP


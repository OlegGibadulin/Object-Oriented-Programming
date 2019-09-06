#ifndef MODELDATAWORK_H
#define MODELDATAWORK_H

#include "errors.h"
#include "model.h"
#include "modelfilework.h"
#include "filework.h"

#include <fstream>

// type of axises
enum typeAxis
{
    X, Y, Z
};

// type of data for shift
struct shiftDataType
{
    double dx, dy, dz;
};

// type of data for scale
struct scaleDataType
{
    double kx, ky, kz;
    double cx, cy, cz;
};

// type of data for turn
struct turnDataType
{
    int angle;
    double cx, cy, cz;
    typeAxis axis;
};

// type of data for parallel projection
struct projectPDataType
{
    typeAxis axis;
};

// type of data for central projection
struct projectCDataType
{
    typeAxis axis;
    double distanse;
};

// type of parameters of data
union paramType
{
    shiftDataType shiftData;
    scaleDataType scaleData;
    turnDataType turnData;
    projectPDataType projectPData;
    projectCDataType projectCData;
};

// data for action
struct actionDataType
{
    char* fileName;
    paramType param;
};

// load model
typeError modelLoadData(modelType& model, const actionDataType data);

// save model
typeError modelSaveData(const modelType model, const actionDataType data);

// shift model
typeError modelShiftData(const modelType &model, const actionDataType data);

// scale model
typeError modelScaleData(const modelType &model, const actionDataType data);

// turn model
typeError modelTurnData(const modelType &model, const actionDataType data);

// project (parallel) model
typeError modelProjectPData(const modelType &model, const actionDataType data);

// project (central) model
typeError modelProjectCData(const modelType &model, const actionDataType data);

// draw model on display
typeError modelDrawData(const modelType model);

#include "modelparamwork.h"

#endif // MODELDATAWORK_H


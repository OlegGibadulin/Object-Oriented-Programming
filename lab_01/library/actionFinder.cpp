#ifndef ACTIONFINDER_CPP
#define ACTIONFINDER_CPP

#include "actionFinder.h"

typeError actionFinder(const typeAction action, const struct actionDataType data)
{
    static modelType model = modelInit();

    typeError error = OK;

    switch (action)
    {
        case actionLoad:
            error = modelLoadData(model, data);
            break;
        case actionSave:
            error = modelSaveData(model, data);
            break;
        case actionFree:
            error = modelFree(model);
            break;
        case actionDraw:
            error = modelDrawData(model);
            break;
        case actionShift:
            error = modelShiftData(model, data);
            break;
        case actionScale:
            error = modelScaleData(model, data);
            break;
        case actionTurn:
            error = modelTurnData(model, data);
            break;
        case actionProjectP:
            error = modelProjectPData(model, data);
            break;
        case actionProjectC:
            error = modelProjectCData(model, data);
            break;
        default:
            error = ErrorAction;
    }

    return error;
}

#endif // ACTIONFINDER_CPP

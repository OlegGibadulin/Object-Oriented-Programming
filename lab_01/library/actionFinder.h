#ifndef ACTIONFINDER_H
#define ACTIONFINDER_H

#include "errors.h"
#include "modeldatawork.h"
#include "model.h"

// types of library actions
enum typeAction
{
    actionLoad,
    actionSave,
    actionFree,
    actionDraw,
    actionShift,
    actionScale,
    actionTurn,
    actionProjectP,
    actionProjectC
};

// find action and exution needed function
typeError actionFinder(const typeAction action, const struct actionDataType data);

#endif // ACTIONFINDER_H

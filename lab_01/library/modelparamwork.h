#ifndef MODELPARAMWORK_H
#define MODELPARAMWORK_H

#include "modeltransform.h"
#include "modelproject.h"
#include "display.h"
#include "nodearray.h"
#include "edgearray.h"

// find out shift parametres
typeError modelShiftParam(const nodeArrType &nodeArr, const union paramType param);

// find out scale parametres
typeError modelScaleParam(const nodeArrType &nodeArr, const union paramType param);

// find out turn parametres
typeError modelTurnParam(const nodeArrType &nodeArr, const union paramType param);

// find out parallel projection parametres
typeError modelProjectPParam(const nodeArrType &nodeArr, const union paramType param);

// find out central projection parametres
typeError modelProjectCParam(const nodeArrType &nodeArr, const union paramType param);

// find out parametres for drawing
typeError modelDrawParam(const edgeArrType edgeArr, const nodeArrType nodeArr);

#endif // MODELPARAMWORK_H


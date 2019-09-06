#ifndef MODELPARAMWORK_CPP
#define MODELPARAMWORK_CPP

#include "modelparamwork.h"

typeError modelShiftParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelShift(nodeArr.nodes, param.shiftData, nodeArr.size);
}

typeError modelScaleParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelScale(nodeArr.nodes, param.scaleData, nodeArr.size);
}

typeError modelTurnParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelTurn(nodeArr.nodes, param.turnData, nodeArr.size);
}

typeError modelProjectPParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelProjectP(nodeArr.nodes, param.projectPData, nodeArr.size);
}

typeError modelProjectCParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelProjectC(nodeArr.nodes, param.projectCData, nodeArr.size);
}

typeError modelDrawParam(const edgeArrType edgeArr, const nodeArrType nodeArr)
{
    return drawDisplay(edgeArr.edges, nodeArr.nodes, edgeArr.size);
}

#endif // MODELPARAMWORK_CPP


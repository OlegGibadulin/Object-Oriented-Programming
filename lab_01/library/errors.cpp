#ifndef ERROR_CPP
#define ERROR_CPP

#include "errors.h"

const char* getErrorMsg(const typeError error)
{
    switch (error)
    {
        case OK:
            return "OK";
        case ErrorFileOpen:
            return "Error file: open";
        case ErrorFileRead:
            return "Error file: read";
        case ErrorFileSave:
            return "Error file: save";
        case ErrorFileName:
            return "Error file: name is empty";
        case ErrorAllocation:
            return "Error memory: bad allocation";
        case ErrorFree:
            return "Error memory: bad free";
        case ErrorModelInit:
            return "Error model: not inizialisation";
        case ErrorEdgesExist:
            return "Error edge array: not inizialisation";
        case ErrorNodesExist:
            return "Error node array: not inizialisation";
        case ErrorAction:
            return "Error type of action: not defined";
        case ErrorField:
            return "Error type of field: not defined";
        default:
            return "Error type of error: not defined";
    }
}

#endif // ERROR_CPP


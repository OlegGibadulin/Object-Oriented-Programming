#ifndef ERRORS_H
#define ERRORS_H

// types of library errors
enum typeError
{
    OK = 0,
    ErrorFileOpen = 1,
    ErrorFileRead,
    ErrorFileSave,
    ErrorFileName,
    ErrorAllocation,
    ErrorFree,
    ErrorModelInit,
    ErrorEdgesExist,
    ErrorNodesExist,
    ErrorAction,
    ErrorField
};

// get message of error
const char* getErrorMsg(const typeError error);

#endif // ERRORS_H


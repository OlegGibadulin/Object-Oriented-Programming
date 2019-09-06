#ifndef FILEWORK_CPP
#define FILEWORK_CPP

#include "filework.h"

bool isEmptyFile(FILE* f)
{
    const long place = ftell(f);
    fseek(f, 0, SEEK_END);

    if (place == ftell(f))
        return true;

    fseek(f, place, SEEK_SET);

    return false;
}

bool isOpenFile(const FILE* f)
{
    return f ? true : false;
}

typeError checkFileForOpen(const FILE* f)
{
    return isOpenFile(f) ? OK : ErrorFileOpen;
}

typeError isFileNameEmpty(const char* fileName)
{
    return fileName[0] == '\0' ? ErrorFileName : OK;
}

typeError fileTypeInit(fileWorkType& file)
{
    file.f = NULL;

    return OK;
}

typeError openFileForRead(fileWorkType& file, const char* fileName)
{
    file.f = fopen(fileName, "r");
    return isOpenFile(file.f) ? OK : ErrorFileOpen;
}

typeError openFileForWrite(fileWorkType& file, const char* fileName)
{
    file.f = fopen(fileName, "w");
    return isOpenFile(file.f) ? OK : ErrorFileOpen;
}

typeError isCorrectFile(FILE* f)
{
    if (!isOpenFile(f))
        return ErrorFileOpen;

    return isEmptyFile(f) ? ErrorFileRead : OK;
}

typeError getSize(unsigned int& size, FILE* f)
{
    return fscanf(f, "%u", &size) == READ_OK ? OK : ErrorFileRead;
}

typeError setSize(FILE* f, const unsigned int size)
{
    return fprintf(f, "%u\n\n", size) < WRITE_OK ? ErrorFileSave : OK;
}

typeError getEdgeData(unsigned int& data, FILE* f)
{
    return fscanf(f, "%u", &data) == READ_OK ? OK : ErrorFileRead;
}

typeError setEdgeData(FILE* f, const unsigned int data)
{
    return fprintf(f, "%u ", data) < WRITE_OK ? ErrorFileSave : OK;
}

typeError getNodeData(double& data, FILE *f)
{
    float tmp;
    if (fscanf(f, "%f", &tmp) != READ_OK)
        return ErrorFileRead;
    data = tmp;

    return OK;
}

typeError setNodeData(FILE *f, const double data)
{
    float tmp = data;
    return fprintf(f, "%f ", tmp) < WRITE_OK ? ErrorFileSave : OK;
}

#endif // FILEWORK_CPP


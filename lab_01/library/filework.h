#ifndef FILEWORK_H
#define FILEWORK_H

#include "errors.h"

#include <fstream>

#define READ_OK 1
#define WRITE_OK 1

struct fileWorkType
{
    FILE* f;
};

// check for empty file
bool isEmptyFile(FILE* f);

// check for open file
bool isOpenFile(const FILE* f);

// check for open file
typeError checkFileForOpen(const FILE* f);

// check for empty file name
typeError isFileNameEmpty(const char* fileName);

typeError fileTypeInit(fileWorkType& file);

// open file for read and check for open
typeError openFileForRead(fileWorkType &file, const char* fileName);

// open file for write and check for open
typeError openFileForWrite(fileWorkType &file, const char* fileName);

// check for correct file
typeError isCorrectFile(FILE* f);

// get size data (nodes or edges) from file
typeError getSize(unsigned int& size, FILE* f);

// set size data (nodes or edges) to file
typeError setSize(FILE* f, const unsigned int size);

// get edge data from file
typeError getEdgeData(unsigned int& data, FILE* f);

// set edge data to file
typeError setEdgeData(FILE* f, const unsigned int data);

// get node data from file
typeError getNodeData(double &data, FILE *f);

// set node data from file
typeError setNodeData(FILE *f, const double data);

#endif // FILEWORK_H


#ifndef MODELFILEWORK_H
#define MODELFILEWORK_H

#include "errors.h"
#include "model.h"

#include <fstream>

// filling of data structures of nodes and edges from file
typeError modelLoad(modelType& model, fileWorkType file);

// filling of file by nodes and edges data
typeError modelSave(const modelType model, fileWorkType file);

#endif // MODELFILEWORK_H


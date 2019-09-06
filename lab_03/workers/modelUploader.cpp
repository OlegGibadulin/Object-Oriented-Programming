#ifndef UPLOADER_HPP
#define UPLOADER_HPP

#include "modelUploader.h"

ModelUploader::ModelUploader(const std::string& fileName) : fileName(fileName) {}

std::shared_ptr<Model> ModelUploader::uploadModel(BaseBuilder& bld)
{
    try
    {
        bld.buildModel();

        size_t countEdges;
        size_t src, purp;

        file >> countEdges;

        for (size_t i = 0; i < countEdges; ++i)
        {
            file >> src >> purp;
            bld.buildEdge(src, purp);
        }

        size_t countNodes;
        double x, y, z;

        file >> countNodes;

        for (size_t i = 0; i < countNodes; ++i)
        {
            file >> x >> y >> z;
            bld.buildNode(x, y, z);
        }
    }
    catch (const std::ifstream::failure& e)
    {
        throw ReadFileException();
    }

    return bld.getModel();
}

void ModelUploader::openSrc()
{
    this->file.open(this->fileName);
    if (!file)
        throw OpenFileException();
}

void ModelUploader::closeSrc()
{
    try
    {
        this->file.close();
    }
    catch (const std::ifstream::failure& e)
    {
        throw CloseFileException();
    }
}

#endif // UPLOADER_HPP


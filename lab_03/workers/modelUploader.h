#ifndef MODELUPLOADER_H
#define MODELUPLOADER_H

#include "exceptions/uploaderException.h"
#include "workers/modelBuilder.h"

#include <fstream>

class BaseUploader
{
public:
    BaseUploader() = default;
    virtual ~BaseUploader() = default;

    virtual std::shared_ptr<Model> uploadModel(BaseBuilder& bld) = 0;
    virtual void openSrc() = 0;
    virtual void closeSrc() = 0;
};

class ModelUploader : public BaseUploader
{
public:
    explicit ModelUploader(const std::string& fileName);
    ~ModelUploader() = default;

    std::shared_ptr<Model> uploadModel(BaseBuilder &bld) override;

    void openSrc() override;
    void closeSrc() override;

private:
    std::string fileName;
    std::ifstream file;
};

#endif // MODELUPLOADER_H


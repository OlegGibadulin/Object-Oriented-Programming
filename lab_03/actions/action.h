#ifndef ACTION_H
#define ACTION_H

#include "facade/facade.h"
#include "workers/modelBuilder.h"
#include "workers/modelUploader.h"
#include "workers/objecttransformator.h"
#include "transformations/transformations.h"

class BaseAction
{
public:
    BaseAction() = default;
    virtual ~BaseAction() = default;

    virtual void execute(std::shared_ptr<Facade> facade) = 0;
};

namespace actions
{
class ModelUploadAction : public BaseAction
{
public:
    explicit ModelUploadAction(const std::string& fileName) : fileName(fileName) {}
    ~ModelUploadAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        ModelUploader uploader(fileName);
        ModelBuilder builder;
        facade->addModel(uploader, builder);
    }
private:
    std::string fileName;
};

class CameraAddAction : public BaseAction
{
public:
    explicit CameraAddAction(const double angleX, const double angleY, \
        const double angleZ) : angleX(angleX), angleY(angleY), angleZ(angleZ) {}
    ~CameraAddAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        facade->addCamera();
    }
private:
    double angleX, angleY, angleZ;
};

class CameraRemoveAction : public BaseAction
{
public:
    explicit CameraRemoveAction(const size_t index) : index(index) {}
    ~CameraRemoveAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        facade->removeCamera(this->index);
    }
private:
    size_t index;
};

class ModelShiftAction : public BaseAction
{
public:
    explicit ModelShiftAction(const double dx, const double dy, \
                              const double dz, const ssize_t index) :
        dx(dx), dy(dy), dz(dz), modelIndex(index) {}
    ~ModelShiftAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        transformtions::Shifting shf(dx, dy, dz);
        ModelTransformator transformator(shf);
        facade->transformModel(transformator, modelIndex);
    }
private:
    double dx, dy, dz;
    ssize_t modelIndex;
};

class ModelScaleAction : public BaseAction
{
public:
    explicit ModelScaleAction(const double kx, const double ky, \
                              const double kz, const size_t index) :
        kx(kx), ky(ky), kz(kz), modelIndex(index) {}
    ~ModelScaleAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        transformtions::Scaling scl(kx, ky, kz);
        ModelTransformator transformator(scl);
        facade->transformModel(transformator, modelIndex);
    }
private:
    double kx, ky, kz;
    size_t modelIndex;
};

class ModelRotateAction : public BaseAction
{
public:
    explicit ModelRotateAction(const double x, const double y, const double z,
                                const size_t index) :
        angleX(x), angleY(y), angleZ(z), modelIndex(index) {}
    ~ModelRotateAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        transformtions::Rotation rt(angleX, angleY, angleZ);
        ModelTransformator transformator(rt);
        facade->transformModel(transformator, modelIndex);
    }
private:
    double angleX, angleY, angleZ;
    size_t modelIndex;
};

class CameraRotateAction : public BaseAction
{
public:
    explicit CameraRotateAction(const double x, const double y, const double z,
                                const size_t index)
        : angleX(x), angleY(y), angleZ(z), cameraIndex(index) {}
    ~CameraRotateAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        transformtions::Rotation rt(angleX, angleY, angleZ);
        CameraTransformator transformator(rt);
        facade->transformCamera(transformator, cameraIndex);
    }
private:
    double angleX, angleY, angleZ;
    size_t cameraIndex;
};

class ModelDrawAction : public BaseAction
{
public:
    explicit ModelDrawAction(ModelDrawer drw, const size_t index)
        : drawer(drw), cameraIndex(index) {}
    ~ModelDrawAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        facade->draw(drawer, cameraIndex);
    }
private:
    ModelDrawer drawer;
    size_t cameraIndex;
};
}

#endif // ACTION_H

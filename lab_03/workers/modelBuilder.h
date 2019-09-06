#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "object/model.h"
#include "exceptions/builderException.h"

#include <iostream>
#include <memory>

class BaseBuilder
{
public:
    BaseBuilder() = default;
    virtual ~BaseBuilder() = default;

    virtual std::shared_ptr<Model> getModel() const = 0;
    virtual void buildModel() = 0;
    virtual void buildNode(const double x, const double y, const double z) = 0;
    virtual void buildEdge(const size_t src, const size_t purp) = 0;
};

class ModelBuilder : public BaseBuilder
{
public:
    ModelBuilder();
    ~ModelBuilder() = default;

    std::shared_ptr<Model> getModel() const;
    void buildModel();
    void buildNode(const double x, const double y, const double z);
    void buildEdge(const size_t src, const size_t purp);

protected:
    bool isModelBuilt() const;

protected:
    std::shared_ptr<Model> model;
};

#endif // MODELBUILDER_H


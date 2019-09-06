#ifndef MODELBUILDER_HPP
#define MODELBUILDER_HPP

#include "modelBuilder.h"

ModelBuilder::ModelBuilder() : model(nullptr) {}

std::shared_ptr<Model> ModelBuilder::getModel() const
{
    return model;
}

void ModelBuilder::buildModel()
{
    model = std::make_shared<Model>();
}

void ModelBuilder::buildNode(const double x, const double y, const double z)
{
    if (!isModelBuilt())
        throw NoBuildingObjectException();

    Node node(x, y, z);
    this->model->addNode(node);
}

void ModelBuilder::buildEdge(const size_t src, const size_t purp)
{
    if (!isModelBuilt())
        throw NoBuildingObjectException();

    Edge edge(src, purp);
    this->model->addEdge(edge);
}

bool ModelBuilder::isModelBuilt() const
{
    return (this->model == nullptr) ? false : true;
}

#endif // MODELBUILDER_HPP


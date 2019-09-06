#include "drawmanager.h"

void DrawManager::drawModel(BaseDrawer& drw, const ObjIter& b, const ObjIter& e, \
               std::shared_ptr<Object> obj)
{
    std::shared_ptr<Camera> cm = std::static_pointer_cast<Camera>(obj);
    for (ObjIter iter = b; iter != e; ++iter)
    {
        if (!(*iter))
            throw NoDrawingObjectException();

        if ((*iter)->isVisible())
        {
            std::shared_ptr<Model> model = std::static_pointer_cast<Model>(*iter);

            const std::vector<Edge> edges = model->getEdges();
            if (edges.empty())
                throw NoDrawingEdgesException();

            std::vector<Node> nodes = model->getNodes();
            if (nodes.empty())
                throw NoDrawingNodesException();

            for (size_t i = 0; i < nodes.size(); ++i)
            {
                nodes[i].shift(cm->getShX(), cm->getShY(), cm->getShZ());
                nodes[i].scale(cm->getScX(), cm->getScY(), cm->getScZ());

                nodes[i].rotateX(cm->getRtX());
                nodes[i].rotateY(cm->getRtY());
                nodes[i].rotateZ(cm->getRtZ());
            }

            for (size_t i = 0; i < edges.size(); ++i)
            {
                const Node& src = nodes[edges[i].getSrc()];
                const Node& purp = nodes[edges[i].getPurp()];
                drw.drawLine(getX(src.getX(), src.getZ()), getY(src.getY(), src.getZ()),
                             getX(purp.getX(), purp.getZ()), getY(purp.getY(), purp.getZ()));
            }
        }
    }
}

double DrawManager::getX(const double x, const double z) const
{
    return x + z * coeff3D;
}

double DrawManager::getY(const double y, const double z) const
{
    return -y - z * coeff3D;
}

#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "gui/drawer.h"
#include "object/compositeobject.h"
#include "exceptions/drawerException.h"

class DrawManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void drawModel(BaseDrawer &drw, const ObjIter& b, const ObjIter& e, \
                   std::shared_ptr<Object> obj);

private:
    static constexpr double coeff3D = 0.5;

    double getX(const double x, const double z) const;
    double getY(const double y, const double z) const;
};

#endif // DRAWMANAGER_H

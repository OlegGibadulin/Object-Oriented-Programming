#include "lift.h"

Lift::Lift(QObject *parent) : QObject(parent)
{
    QObject::connect(&controller, SIGNAL(purpFloorAppeared(size_t)),
                     &cabin,  SLOT(setPurpFloor(size_t)));

    QObject::connect(&cabin,  SIGNAL(updateCabinCurState(size_t, Direction, bool)),
                     &controller, SLOT(setCabinCurState(size_t, Direction, bool)));

    QObject::connect(&cabin,  SIGNAL(purpFloorIsReached()),
                     &controller, SLOT(reachPurpFloor()));
}

QWidget* Lift::getWidget()
{
    return &controller;
}

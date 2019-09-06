#ifndef CABIN_H
#define CABIN_H

#include "door.h"
#include "direction.h"

#include <QObject>
#include <iostream>

class Cabin : public QObject
{
    Q_OBJECT

public:
    explicit Cabin();
    ~Cabin() = default;

signals:
    void updateCabinCurState(size_t floor, Direction d, bool floorIsReached = false);
    void letStopCabin();
    void letMoveCabin();
    void purpFloorIsReached();

public slots:
    void moveCabin();
    void setPurpFloor(size_t floor);
    void stopedOpenedCabin();

private slots:
    void stopedClosedCabin();

private:
    enum CabinState
    {
        STAYING_OPENED,
        STAYING_CLOSED,
        MOVING
    };

    Door door;
    CabinState cabinState;
    Direction direction;
    size_t curFloor;
    size_t purpFloor;
    QTimer timerMoving;
};

#endif // CABIN_H

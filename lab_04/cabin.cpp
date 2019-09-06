#include "cabin.h"

Cabin::Cabin() : cabinState(STAYING_CLOSED), direction(NOMOVEMENT),
    curFloor(0), purpFloor(0)
{
    QObject::connect(&timerMoving, SIGNAL(timeout()), this, SLOT(moveCabin()));
    QObject::connect(this, SIGNAL(letMoveCabin()), this, SLOT(moveCabin()));
    QObject::connect(this, SIGNAL(letStopCabin()), this, SLOT(stopedClosedCabin()));
    QObject::connect(&door, SIGNAL(doorsAreClosed()), this, SLOT(stopedOpenedCabin()));
}

void Cabin::moveCabin()
{
    if (cabinState == MOVING)
    {
        if (curFloor == purpFloor)
            emit letStopCabin();
        else
        {
            std::cout << "Cabin is moving, floor: " << curFloor << std::endl;
            if (curFloor < purpFloor)
            {
                curFloor += 1;
                direction = UP;
            }
            else
            {
                curFloor -= 1;
                direction = DOWN;
            }
            emit updateCabinCurState(curFloor - direction, direction);
            timerMoving.start(TimeConst::CABIN_MOVING);
        }
    }
}

void Cabin::stopedClosedCabin()
{
    if (cabinState == MOVING)
    std::cout << "Cabin stopped, floor: " << curFloor << std::endl;
    cabinState = STAYING_CLOSED;
    emit updateCabinCurState(curFloor, direction, true);
    emit door.openDoor();
}

void Cabin::stopedOpenedCabin()
{
    if (cabinState == STAYING_CLOSED)
    {
        cabinState = STAYING_OPENED;
        emit purpFloorIsReached();
    }
}

void Cabin::setPurpFloor(size_t floor)
{
    cabinState = MOVING;
    purpFloor = floor;
    emit letMoveCabin();
}

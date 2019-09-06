#include "door.h"

Door::Door()
{
    doorState = CLOSED;

    QObject::connect(this, SIGNAL(openDoor()), this, SLOT(openingDoor()));
    QObject::connect(&timerOpening, SIGNAL(timeout()), this, SLOT(openedDoor()));

    QObject::connect(&timerOpened, SIGNAL(timeout()), this, SLOT(closingDoor()));
    QObject::connect(&timerClosing, SIGNAL(timeout()), this, SLOT(closedDoor()));
}

void Door::openingDoor()
{
    if (doorState == CLOSED)
    {
        doorState = OPENING;
        std::cout << "Doors are opening" << std::endl;
        timerOpening.start(TimeConst::DOOR_MOVING);
    }
    else if (doorState == CLOSING)
    {
        doorState = OPENING;
        std::cout << "Doors are opening" << std::endl;
        size_t tmp = timerClosing.remainingTime();
        timerClosing.stop();
        timerOpening.start(TimeConst::DOOR_MOVING - tmp);
    }
}

void Door::openedDoor()
{
    if (doorState == OPENING)
    {
        doorState = OPENED;
        std::cout << "Doors opened" << std::endl;
        timerOpened.start(TimeConst::DOOR_WAITING);
    }
}

void Door::closingDoor()
{
    if (doorState == OPENED)
    {
        doorState = CLOSING;
        std::cout << "Doors are closing" << std::endl;
        timerClosing.start(TimeConst::DOOR_MOVING);
    }
}

void Door::closedDoor()
{
    if (doorState == CLOSING)
    {
        doorState = CLOSED;
        std::cout << "Doors closed" << std::endl;
        emit doorsAreClosed();
    }
}

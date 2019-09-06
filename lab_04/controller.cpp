#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent), controllerState(READY),
    direction(NOMOVEMENT), curFloor(0)
{
    layout = new QVBoxLayout;
    this->setLayout(layout);

    for (size_t i = 0; i < countFloors; ++i)
    {
        buttons[i] = new Button;
        buttons[i]->setText(QString::number(i));
        layout->addWidget(dynamic_cast<QPushButton*>(buttons[i]));

        buttons[i]->setFloorNumber(i);
        QObject::connect(buttons[i], SIGNAL(buttonIsPushed(size_t)),
                         this, SLOT(setPurpFloor(size_t)));

        purpFloors[i] = false;
    }
}

Controller::~Controller()
{
    for (size_t i = 0; i < countFloors; ++i)
    {
        delete buttons[i];
    }
    delete layout;
}

void Controller::setCabinCurState(size_t floor, Direction direct, bool floorIsReached)
{
    this->curFloor = floor;
    this->direction = direct;
    if (floorIsReached)
        controllerState = WAITING;
}

void Controller::setPurpFloor(size_t floor)
{
    purpFloors[floor] = true;

    if (controllerState == READY || curFloor == floor)
    {
        getNextPurpFloor(floor);
        emit purpFloorAppeared(floor);
    }
}

void Controller::reachPurpFloor()
{
    if (controllerState == WAITING)
    {
        controllerState = READY;
        purpFloors[curFloor] = false;
        emit buttons[curFloor]->resetButton();
        size_t floor;

        if (getNextPurpFloor(floor))
            emit purpFloorAppeared(floor);
        else
            direction = NOMOVEMENT;
    }
}

bool Controller::getNextPurpFloor(size_t &floor)
{
    int step = (direction == NOMOVEMENT) ? DOWN : direction;

    for(size_t i = curFloor + direction; i < countFloors && i >= 0; i += step)
    {
        if(purpFloors[i])
        {
            floor = i;
            return true;
        }
    }

    step = step * -1;

    for(int i = curFloor; i < countFloors && i >= 0; i += step)
    {
        if(purpFloors[i])
        {
            floor = i;
            return true;
        }
    }

    return false;
}

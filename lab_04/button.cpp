#include "button.h"

Button::Button(QWidget *parent) : QPushButton(parent),
    buttonState(PUSHED_UP), floorNumber(0)
{
    QObject::connect(this, SIGNAL(resetButton()), this, SLOT(pushUpButton()));
    QObject::connect(this, SIGNAL(clicked(bool)), this, SLOT(pushDownButton()));
}

void Button::setFloorNumber(size_t floor)
{
    this->floorNumber = floor;
}

void Button::pushDownButton()
{
    /*emit buttonIsPushed(floorNumber);
    buttonState = PUSHED_DOWN;*/

    if (buttonState == PUSHED_UP)
    {
        buttonState = PUSHED_DOWN;
        this->setEnabled(false);
        emit buttonIsPushed(floorNumber);
    }
}

void Button::pushUpButton()
{
    if (buttonState == PUSHED_DOWN)
    {
        buttonState = PUSHED_UP;
        this->setEnabled(true);
    }
}

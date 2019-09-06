#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "button.h"
#include "direction.h"
#include "door.h"

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <iostream>

class Controller : public QWidget
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = 0);
    ~Controller();

signals:
    void purpFloorAppeared(size_t floor);

public slots:
    void setCabinCurState(size_t floor, Direction direct, bool floorIsReached);
    void setPurpFloor(size_t floor);
    void reachPurpFloor();

private:
    static constexpr size_t countFloors = 10;
    enum ControllerState
    {
        READY,
        WAITING
    };

    QVBoxLayout* layout;
    Button* buttons[countFloors];
    bool purpFloors[countFloors];

    ControllerState controllerState;
    Direction direction;
    size_t curFloor;

    bool getNextPurpFloor(size_t &floor);
};

#endif // CONTROLLER_H

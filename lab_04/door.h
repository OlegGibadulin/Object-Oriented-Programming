#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>
#include <iostream>

class TimeConst
{
public:
    static constexpr size_t DOOR_MOVING = 500;
    static constexpr size_t DOOR_WAITING = 500;
    static constexpr size_t CABIN_MOVING = 500;
};

class Door : public QObject
{
    Q_OBJECT

public:
    explicit Door();
    ~Door() = default;

signals:
    void doorsAreClosed();
    void openDoor();

public slots:
    void openingDoor();

private slots:
    void openedDoor();
    void closingDoor();
    void closedDoor();

private:
    enum DoorState
    {
        OPENED,
        CLOSED,
        OPENING,
        CLOSING
    };

    QTimer timerOpening;
    QTimer timerClosing;
    QTimer timerOpened;
    DoorState doorState;
};

#endif // DOOR_H

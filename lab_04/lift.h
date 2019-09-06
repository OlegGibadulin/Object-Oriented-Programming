#ifndef LIFT_H
#define LIFT_H

#include "direction.h"
#include "controller.h"
#include "cabin.h"

#include <QObject>
#include <QWidget>

class Lift : public QObject
{
    Q_OBJECT

public:
    explicit Lift(QObject *parent = 0);
    ~Lift() = default;

    QWidget* getWidget();

private:
    Controller controller;
    Cabin cabin;
};

#endif // CLIFT_H

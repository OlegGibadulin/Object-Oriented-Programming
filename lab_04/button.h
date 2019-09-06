#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QObject>

class Button : public QPushButton
{
    Q_OBJECT

public:
    explicit Button(QWidget *parent = 0);
    ~Button() = default;

    void setFloorNumber(size_t floor);

signals:
    void resetButton();
    void buttonIsPushed(size_t floor);

public slots:
    void pushDownButton();
    void pushUpButton();

private:
    enum ButtonState
    {
        PUSHED_DOWN,
        PUSHED_UP
    };

    ButtonState buttonState;
    size_t floorNumber;
};

#endif // BUTTON_H

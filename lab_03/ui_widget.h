/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QPushButton *LoadButton;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QComboBox *ModelBox;
    QComboBox *CameraBox;
    QGraphicsView *Canvas;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1100, 700);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(700, 0, 371, 700));
        groupBox_2->setAutoFillBackground(true);
        LoadButton = new QPushButton(groupBox_2);
        LoadButton->setObjectName(QStringLiteral("LoadButton"));
        LoadButton->setGeometry(QRect(10, 20, 141, 27));
        AddButton = new QPushButton(groupBox_2);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(200, 20, 141, 27));
        DeleteButton = new QPushButton(groupBox_2);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        DeleteButton->setGeometry(QRect(200, 60, 141, 27));
        ModelBox = new QComboBox(groupBox_2);
        ModelBox->setObjectName(QStringLiteral("ModelBox"));
        ModelBox->setGeometry(QRect(10, 60, 141, 27));
        CameraBox = new QComboBox(groupBox_2);
        CameraBox->setObjectName(QStringLiteral("CameraBox"));
        CameraBox->setGeometry(QRect(200, 100, 141, 27));
        Canvas = new QGraphicsView(groupBox);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->setGeometry(QRect(0, 0, 700, 700));
        Canvas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        LoadButton->setText(QApplication::translate("Widget", "Load", 0));
        AddButton->setText(QApplication::translate("Widget", "Add", 0));
        DeleteButton->setText(QApplication::translate("Widget", "Delete", 0));
#ifndef QT_NO_TOOLTIP
        Canvas->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Canvas->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

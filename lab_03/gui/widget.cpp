#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setUpCanvas();
    ui->ModelBox->addItem("All models");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    try
    {
        ssize_t index = ui->ModelBox->currentIndex() - 1;
        ssize_t indexCamera = ui->CameraBox->currentIndex();

        if (event->key() == Qt::Key_Z)
        {
            actions::ModelShiftAction action(this->offset, 0, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_X)
        {
            actions::ModelShiftAction action(0, this->offset, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_C)
        {
            actions::ModelShiftAction action(0, 0, this->offset, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_R)
        {
            actions::ModelShiftAction action(-this->offset, 0, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_T)
        {
            actions::ModelShiftAction action(0, -this->offset, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_Y)
        {
            actions::ModelShiftAction action(0, 0, -this->offset, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_F)
        {
            actions::ModelScaleAction action(scaleCoeff, scaleCoeff, scaleCoeff, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_G)
        {
            actions::ModelScaleAction action(1 / scaleCoeff, 1 / scaleCoeff, 1 / scaleCoeff, \
                                             index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_Q)
        {
            actions::ModelRotateAction action(angle, 0, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_W)
        {
            actions::ModelRotateAction action(0, angle, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_E)
        {
            actions::ModelRotateAction action(angle, 0, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_A)
        {
            actions::ModelRotateAction action(-angle, 0, 0,  index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_S)
        {
            actions::ModelRotateAction action(0, -angle, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_D)
        {
            actions::ModelRotateAction action(-angle, 0, 0, index);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_J)
        {
            actions::CameraRotateAction action(angle * 2, 0, 0, indexCamera);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_K)
        {
            actions::CameraRotateAction action(0, angle * 2, 0, indexCamera);
            actionController.executeAction(action);
        }
        else if (event->key() == Qt::Key_L)
        {
            actions::CameraRotateAction action(angle * 2, 0, 0, indexCamera);
            actionController.executeAction(action);
        }
    }
    catch (BaseException& e)
    {
        QMessageBox::warning(this, "Error", QString(e.what()));
    }

    this->updateCanvas();
}

void Widget::setUpCanvas()
{
    this->canvas = new QGraphicsScene;
    ui->Canvas->installEventFilter(this);
    ui->Canvas->setScene(canvas);

    ui->AddButton->click();
}

void Widget::updateCanvas()
{
    this->canvas->clear();
    ModelDrawer drawer(this->canvas);

    size_t index = ui->CameraBox->currentIndex();
    actions::ModelDrawAction action(drawer, index);
    actionController.executeAction(action);
}

void Widget::on_AddButton_clicked()
{
    try
    {
        actions::CameraAddAction action(0, 0, 0);
        actionController.executeAction(action);

        ui->CameraBox->addItem("Camera " + QString::number(ui->CameraBox->count()));
        ui->CameraBox->setCurrentIndex(ui->CameraBox->count() - 1);
    }
    catch (BaseException& e)
    {
        QMessageBox::warning(this, "Error", QString(e.what()));
    }
}

void Widget::on_DeleteButton_clicked()
{
    try
    {
        if (ui->CameraBox->count() == 1)
            return;

        actions::CameraRemoveAction action(ui->CameraBox->currentIndex());
        actionController.executeAction(action);

        ui->CameraBox->removeItem(ui->CameraBox->currentIndex());
        ui->CameraBox->setCurrentIndex(0);
    }
    catch (BaseException& e)
    {
        QMessageBox::warning(this, "Error", QString(e.what()));
    }
}

void Widget::on_LoadButton_clicked()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Open model", "", \
                                                        "Wavefront (*.txt)");
        if (filePath.isEmpty())
        {
            QMessageBox::warning(this, "Error", "No file choosen");
            return;
        }

        actions::ModelUploadAction action(filePath.toStdString());
        actionController.executeAction(action);

        ui->ModelBox->addItem("Model " + QString::number(ui->ModelBox->count()));
        ui->ModelBox->setCurrentIndex(ui->ModelBox->count() - 1);

        this->updateCanvas();
    }
    catch (BaseException& e)
    {
        QMessageBox::warning(this, "Error", QString(e.what()));
    }
}

void Widget::on_CameraBox_currentIndexChanged(int index)
{
    this->updateCanvas();
}

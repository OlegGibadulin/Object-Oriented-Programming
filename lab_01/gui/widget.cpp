#ifndef WIDGET_CPP
#define WIDGET_CPP

#include "widget.h"
#include "../ui_widget.h"

std::vector <QPoint> lines;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(QPen(Qt::gray, 1, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(AXIS_GAP_L, CENTER, AXIS_GAP_R, CENTER);
    painter.drawLine(CENTER, AXIS_GAP_L, CENTER, AXIS_GAP_R);
    painter.drawLine(AXIS_GAP_L, AXIS_GAP_R, AXIS_GAP_R, AXIS_GAP_L);

    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));

    for (unsigned int i = 0; i < lines.size(); i += 2)
    {
        painter.drawLine(lines[i].x(), lines[i].y(), lines[i + 1].x(), lines[i + 1].y());
    }
}

void Widget::setLine(QPoint src, QPoint purp)
{
    lines.push_back(src);
    lines.push_back(purp);
}

typeError drawLine(double x1, double y1, double x2, double y2)
{
    QPoint src, purp;
    src.setX(TO_CENTER(x1));
    src.setY(TO_CENTER(y1));
    purp.setX(TO_CENTER(x2));
    purp.setY(TO_CENTER(y2));

    Widget obj;
    obj.setLine(src, purp);

    return OK;
}

void Widget::on_OpenFile_clicked()
{
    QString filePath = QFileDialog::\
            getOpenFileName(this, "Open model", "", "Wavefront (*.txt)");
    if (filePath.isEmpty())
    {
        showError("Error file: not selected");
        return;
    }

    actionDataType data;

    data.fileName = filePath.toLatin1().data();

    typeError error;

    if ((error = actionFinder(actionLoad, data)))
    {
        showError(error);
        return;
    }

    lines.clear();

    if ((error = actionFinder(actionDraw, data)))
        showError(error);

    repaint();
}

void Widget::on_SaveModel_clicked()
{
    QString filePath = QFileDialog::\
            getOpenFileName(this, "Open model", "", "Wavefront (*.txt)");
    if (filePath.isEmpty())
    {
        showError("Error file: not selected");
        return;
    }

    actionDataType data;

    data.fileName = filePath.toLatin1().data();

    typeError error;

    if ((error = actionFinder(actionSave, data)))
        showError(error);

    repaint();
}

void Widget::on_ShiftButton_clicked()
{
    QString strX = ui->ShiftX->text();
    QString strY = ui->ShiftY->text();
    QString strZ = ui->ShiftZ->text();

    if (strX.isEmpty() || strY.isEmpty() || strZ.isEmpty())
    {
        showError("Error input: empty line");
        return;
    }

    bool checkX, checkY, checkZ;

    double dx = strX.toDouble(&checkX);
    double dy = strY.toDouble(&checkY);
    double dz = strZ.toDouble(&checkZ);

    if (!checkX || !checkY || !checkZ)
    {
        showError("Error input: wrong data");
        return;
    }

    actionDataType data;

    data.param.shiftData.dx = dx;
    data.param.shiftData.dy = dy;
    data.param.shiftData.dz = dz;

    typeError error;

    if ((error = actionFinder(actionShift, data)))
    {
        showError(error);
        return;
    }

    lines.clear();

    if ((error = actionFinder(actionDraw, data)))
        showError(error);

    repaint();
}

void Widget::on_ScaleButton_clicked()
{
    QString strKX = ui->ScaleX->text();
    QString strKY = ui->ScaleY->text();
    QString strKZ = ui->ScaleZ->text();
    QString strCX = ui->CenterX->text();
    QString strCY = ui->CenterY->text();
    QString strCZ = ui->CenterZ->text();

    if (strKX.isEmpty() || strKY.isEmpty() || strKZ.isEmpty() || \
            strCX.isEmpty() || strCY.isEmpty() || strCZ.isEmpty())
    {
        showError("Error input: empty line");
        return;
    }

    bool checkKX, checkKY, checkKZ;
    bool checkCX, checkCY, checkCZ;

    double kx = strKX.toDouble(&checkKX);
    double ky = strKY.toDouble(&checkKY);
    double kz = strKZ.toDouble(&checkKZ);
    double cx = strCX.toDouble(&checkCX);
    double cy = strCY.toDouble(&checkCY);
    double cz = strCZ.toDouble(&checkCZ);

    if (!checkKX || !checkKY || !checkKZ || \
            !checkCX || !checkCY || !checkCZ)
    {
        showError("Error input: wrong data");
        return;
    }

    actionDataType data;

    data.param.scaleData.kx = kx;
    data.param.scaleData.ky = ky;
    data.param.scaleData.kz = kz;
    data.param.scaleData.cx = cx;
    data.param.scaleData.cy = cy;
    data.param.scaleData.cz = cz;

    typeError error;

    if ((error = actionFinder(actionScale, data)))
    {
        showError(error);
        return;
    }

    lines.clear();

    if ((error = actionFinder(actionDraw, data)))
        showError(error);

    repaint();
}

void Widget::on_TurnButton_clicked()
{
    QString strX = ui->CenterX->text();
    QString strY = ui->CenterY->text();
    QString strZ = ui->CenterZ->text();
    QString strAngle = ui->TurnAngle->text();

    if (strX.isEmpty() || strY.isEmpty() || strZ.isEmpty() || \
            strAngle.isEmpty())
    {
        showError("Error input: empty line");
        return;
    }

    bool checkX, checkY, checkZ, checkAngle;

    double cx = strX.toDouble(&checkX);
    double cy = strY.toDouble(&checkY);
    double cz = strZ.toDouble(&checkZ);
    int angle = strAngle.toDouble(&checkAngle);

    if (!checkX || !checkY || !checkZ || !checkAngle)
    {
        showError("Error input: wrong data");
        return;
    }

    typeAxis axis;

    if (ui->CheckX->isChecked())
        axis = X;
    else if (ui->CheckY->isChecked())
        axis = Y;
    else
        axis = Z;

    actionDataType data;

    data.param.turnData.cx = cx;
    data.param.turnData.cy = cy;
    data.param.turnData.cz = cz;
    data.param.turnData.angle = angle;
    data.param.turnData.axis = axis;

    typeError error;

    if ((error = actionFinder(actionTurn, data)))
    {
        showError(error);
        return;
    }

    lines.clear();

    if ((error = actionFinder(actionDraw, data)))
        showError(error);

    repaint();
}

void Widget::on_ProjectP_clicked()
{
    typeAxis axis;

    if (ui->CheckX->isChecked())
        axis = X;
    else if (ui->CheckY->isChecked())
        axis = Y;
    else
        axis = Z;

    actionDataType data;

    data.param.projectPData.axis = axis;

    typeError error;

    if ((error = actionFinder(actionProjectP, data)))
    {
        showError(error);
        return;
    }

    lines.clear();

    if ((error = actionFinder(actionDraw, data)))
        showError(error);

    repaint();
}

void Widget::on_ProjectC_clicked()
{
    QString strDistance = ui->Distance->text();

    bool checkDistance;

    double distance = strDistance.toDouble(&checkDistance);

    if (!checkDistance)
    {
        showError("Error input: wrong data");
        return;
    }

    if (strDistance.isEmpty())
    {
        showError("Error input: wrong data");
        return;
    }

    typeAxis axis;

    if (ui->CheckX->isChecked())
        axis = X;
    else if (ui->CheckY->isChecked())
        axis = Y;
    else
        axis = Z;

    actionDataType data;

    data.param.projectCData.distanse = distance;
    data.param.projectCData.axis = axis;

    typeError error;

    if ((error = actionFinder(actionProjectC, data)))
    {
        showError(error);
        return;
    }

    lines.clear();

    if ((error = actionFinder(actionDraw, data)))
        showError(error);

    repaint();
}

void Widget::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, \
    "lab_01", tr("Are you sure?\n"), QMessageBox::No | QMessageBox::Yes, \
    QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes)
    {
        event->ignore();
    }
    else
    {
        typeError error;
        actionDataType data;

        if ((error = actionFinder(actionFree, data)))
            showError(error);

        event->accept();
    }

    typeError error;
    actionDataType data;

    if ((error = actionFinder(actionFree, data)))
        showError(error);
}

#endif // WIDGET_CPP

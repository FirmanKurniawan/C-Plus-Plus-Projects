#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QObject>
#include <QDebug>
#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QPaintEvent>
#include <QSize>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustomButton(QWidget *parent = nullptr, QSize sz = QSize(113,32), QString val = "Tombol");
    ~CustomButton();

protected:
    void PaintEvent(QPaintEvent *ev);

private:
    QRect rect;
    void is_clicked(bool sts);
    void is_pressed();


};

#endif // CUSTOMBUTTON_H

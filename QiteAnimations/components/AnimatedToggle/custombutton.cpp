#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent, QSize sz, QString val)
{
    setCursor(Qt::OpenHandCursor);
    setFixedSize(sz);
    rect = QRect(0,0, this->width(), this->height());
    setText(val);
    connect(this, &QPushButton::pressed, this, &CustomButton::is_pressed);
}

CustomButton::~CustomButton()
{

}

void CustomButton::PaintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);

    p.setBrush(QColor(149, 165, 166));
    p.drawRoundedRect(0,0,rect.width(),this->height(), 25, 25);
}

void CustomButton::is_clicked(bool sts)
{

}

void CustomButton::is_pressed()
{

}

#include "animatedtoggle.h"

AnimatedToggle::AnimatedToggle(QWidget *parent)
{
    //initialization
    setFixedSize(toggle_width, 28);
    setCursor(Qt::PointingHandCursor);

    //create animation
    prop_anim = new QPropertyAnimation(this, "circle_position");
    prop_anim->setEasingCurve(QEasingCurve::InOutQuint);
    prop_anim->setDuration(500);

    prop_col = new QPropertyAnimation(this, "current_color");
    prop_col->setEasingCurve(QEasingCurve::InOutQuint);
    prop_col->setDuration(500);

    connect(this, &QCheckBox::stateChanged, this, &AnimatedToggle::state_berubah);
}

AnimatedToggle::~AnimatedToggle()
{
    //destruction
    disconnect(this, &QCheckBox::stateChanged, this, &AnimatedToggle::state_berubah);
    prop_anim->deleteLater();
    prop_col->deleteLater();
}

void AnimatedToggle::state_berubah(int x)
{
    //write output log when state changes
    qDebug() << Q_FUNC_INFO << QString("State: %1 || x : %2").arg(this->isChecked()).arg(x);

    prop_anim->stop();
    prop_col->stop();
    if (x){
        prop_anim->setEndValue(this->width() - 26);
        prop_col->setEndValue("#00bcff");
    } else {
        prop_anim->setEndValue(3);
        prop_col->setEndValue("#777");
    }

    prop_anim->start();
    prop_col->start();

    qDebug() << Q_FUNC_INFO << QString("bg color: %1 || circle_pos: %2").arg(current_color_var).arg(circle_position_var);
}

//set new hit area?
bool AnimatedToggle::hit_button(QPoint pos)
{
    return this->contentsRect().contains(pos);
}

float AnimatedToggle::circle_position()
{
    return circle_position_var;
}

void AnimatedToggle::set_circle_pos(float pos)
{
    circle_position_var = pos;
    this->update();
}

QString AnimatedToggle::current_color()
{
    return current_color_var;
}

void AnimatedToggle::set_current_color(QString color)
{
    current_color_var = color;
    this->update();
}

//draw custom ui for checkbox
void AnimatedToggle::paintEvent(QPaintEvent *ev)
{
    //init painter
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);

    //draw a rectangle
    QRect rect = QRect(0,0, this->width(), this->height());

    if (!this->isChecked()){
        //draw background
        p.setBrush(QColor(bg_color)); //bg_color
        p.drawRoundedRect(0,0, rect.width(), this->height(), this->height()/2, this->height()/2);

        //draw circle
        p.setBrush(QColor(this->circle_color));
        p.drawEllipse(circle_position(),3,22,22);

        p.setBrush(QColor(0,0,0));
        QRectF rectangle2(circle_position() + 3, (28/2) - 1, 22 - 6, 2);
        p.drawRect(rectangle2);
    } else {
        //draw background
        p.setBrush(QColor(active_color)); //active_color
        p.drawRoundedRect(0,0, rect.width(), this->height(), this->height()/2, this->height()/2);

        //draw circle
        p.setBrush(QColor(this->circle_color));
        p.drawEllipse(circle_position(),3,22,22);

        //draw plus icon
        p.setBrush(QColor(0,0,0));
        QRectF rectangle(circle_position() + (22/2) - 1,6,2,22-6);
        QRectF rectangle2(circle_position() + 3, (28/2) - 1, 22 - 6, 2);

        QVector<QRectF> haa;
        haa.insert(0, rectangle);
        haa.insert(1, rectangle2);

        p.drawRects(haa);

    }

    //end draw mode
    p.end();
}

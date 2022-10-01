#ifndef ANIMATEDTOGGLE_H
#define ANIMATEDTOGGLE_H

#include <QCheckBox>
#include <QDebug>
#include <QObject>
#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QPaintEvent>

class AnimatedToggle : public QCheckBox
{
    Q_OBJECT
    Q_PROPERTY(float circle_position READ circle_position WRITE set_circle_pos USER true);
    Q_PROPERTY(QString current_color READ current_color WRITE set_current_color USER true);
public:
    explicit AnimatedToggle(QWidget *parent = nullptr);
    ~AnimatedToggle();
    float circle_position();
    void set_circle_pos(float pos);

    QString current_color();
    void set_current_color(QString color);

private:
    float circle_position_var = 3;
    int toggle_width = 60;
    QString bg_color = "#777";
    QString circle_color = "#ddd";
    QString active_color = "#00bcff";
    QString current_color_var = "#777";
    QPropertyAnimation *prop_anim;
    QPropertyAnimation *prop_col;


private slots:
    void state_berubah(int x);
    bool hit_button(QPoint pos);



protected:
    void paintEvent(QPaintEvent *ev);
};

#endif // ANIMATEDTOGGLE_H

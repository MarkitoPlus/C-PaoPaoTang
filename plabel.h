#ifndef PLabel_H
#define PLabel_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QCursor>


class PLabel: public QLabel
{
Q_OBJECT

public:
    PLabel();

    ~PLabel();

    void Ini(QString default_pixmap_url, QString enter_pixmap_url);

public:
    void enterEvent(QEvent* ev);

    void leaveEvent(QEvent* ev);

    void mousePressEvent(QMouseEvent *ev);

signals:
    void Mouse_Clicked();

private:
    QPixmap* _default_pixmap; //默认显示图片

    QPixmap* _enter_pixmap; //当鼠标进入时显示的图片
};

#endif // PLabel_H

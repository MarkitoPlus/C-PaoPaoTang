#include "plabel.h"


PLabel::PLabel(){
    qDebug() << "Create an empty PLabel";
}

PLabel::~PLabel(){
    delete _default_pixmap;
    delete _enter_pixmap;
}

void PLabel::Ini(QString default_pixmap_url, QString enter_pixmap_url){
    _default_pixmap = new QPixmap(default_pixmap_url);
    _enter_pixmap = new QPixmap(enter_pixmap_url);
    setPixmap(*_default_pixmap);
}

void PLabel::enterEvent(QEvent *ev){
    Q_UNUSED(ev);
    setPixmap(*_enter_pixmap);
    setCursor(Qt::PointingHandCursor);
}

void PLabel::leaveEvent(QEvent *ev){
    Q_UNUSED(ev);
    setPixmap(*_default_pixmap);
    setCursor(Qt::ArrowCursor);
}

void PLabel::mousePressEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton)
        emit(Mouse_Clicked());
}





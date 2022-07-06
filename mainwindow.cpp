#include "mainwindow.h"
#include "ui_mainwindow.h"

QVector<QString> scene_url_{
    ":/img/start.png",
    ":/img/moden.jpg",
    ":/img/moden.jpg",
    ":/img/moden.jpg",
    ":/img/jsh.jpg",
    ":/img/daoju.jpg"
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Ini_MainWindow();
    Show_Scene(Scene_Ref::Welcome_Scene);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Ini_MainWindow(){
    setFixedSize(1000, 800);
    ui->frame->setFixedSize(1000, 800);
}

void MainWindow::Clear_List(){
    for(auto ir = _plabel_list.begin(); ir != _plabel_list.end(); ir++)
        delete *ir;
    _plabel_list.clear();
}

void MainWindow::Ini_Label(MainWindow *parent, int x, int y, int w, int h, QString default_label_url, QString enter_label_url){
    PLabel * _start_label = new PLabel();
    _plabel_list.push_back(_start_label);
    _start_label->setParent(parent);
    _start_label->Ini(default_label_url, enter_label_url);
    _start_label->move(x, y);
    _start_label->setFixedSize(w, h);
    _start_label->setScaledContents(true);
    _start_label->show();
}

void MainWindow::Show_Scene(Scene_Ref scene){
    Clear_List();
    QString str_set_scene = QString("QWidget#%1{ border-image: url(%2);}").arg(objectName().toUtf8().data()).\
            arg(scene_url_.at(scene).toUtf8().data());
    setStyleSheet(str_set_scene);
    switch (scene) {
        case Scene_Ref::Welcome_Scene:
            Ini_Label(this, 330, 450, 150, 140, QString(":/img/play.png"), QString(":/img/play1.png"));
            Ini_Label(this, 330, 550, 150, 140, QString(":/img/itr.png"), QString(":/img/itr1.png"));
            connect(_plabel_list.at(0), &PLabel::Mouse_Clicked, [=](){
                Show_Scene(Scene_Ref::Mode_Scene);
            });
            connect(_plabel_list.at(1), &PLabel::Mouse_Clicked, [=](){
                Show_Scene(Scene_Ref::Introduction_Control_Scene);
            });
            break;
        case Scene_Ref::Mode_Scene:
            Ini_Label(this, 250, 350, 120, 68, QString(":/img/b2.png"), QString(":/img/b2.png"));
            Ini_Label(this, 250, 450, 120, 68, QString(":/img/b3.png"), QString(":/img/b3.png"));
            Ini_Label(this, 250, 550, 120, 68, QString(":/img/b1.png"), QString(":/img/b1.png"));
            connect(_plabel_list.at(2), &PLabel::Mouse_Clicked, [=](){
                Show_Scene(Scene_Ref::Welcome_Scene);
            });
            connect(_plabel_list.at(0), &PLabel::Mouse_Clicked, [=](){
                Show_Scene(Scene_Ref::Single_Mode_Scene);
            });
            connect(_plabel_list.at(1), &PLabel::Mouse_Clicked, [=](){
                Show_Scene(Scene_Ref::Double_Mode_Scene);
            });
            break;
        case Scene_Ref::Introduction_Control_Scene:
            Ini_Label(this, 100, 650, 100, 45, QString(":/img/bk.png"), QString(":/img/bk.png"));
            Ini_Label(this, 260, 650, 100, 45, QString(":/img/tool.png"), QString(":/img/tool.png"));
            connect(_plabel_list.at(0), &PLabel::Mouse_Clicked, [=](){
                Show_Scene(Scene_Ref::Welcome_Scene);
            });
            connect(_plabel_list.at(1), &PLabel::Mouse_Clicked, [=](){
                Show_Scene(Scene_Ref::Introduction_Tool_Scene);
            });
            break;
        case Scene_Ref::Introduction_Tool_Scene:
            Ini_Label(this, 100, 650, 100, 45, QString(":/img/bk.png"), QString(":/img/bk.png"));
            connect(_plabel_list.at(0), &PLabel::Mouse_Clicked, [=](){
                Show_Scene(Scene_Ref::Welcome_Scene);
            });
            break;
        case Scene_Ref::Single_Mode_Scene:
            qDebug() << " Single Game Begin";
            break;
        case Scene_Ref::Double_Mode_Scene:
            qDebug() << " Double Game Begin";
            break;
    }
}





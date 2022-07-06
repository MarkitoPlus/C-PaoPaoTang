#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QList>
#include <QVector>
#include <QMouseEvent>
#include <QDebug>
#include "plabel.h"
#include "imgref.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void Ini_MainWindow();

    void Clear_List();

    void Show_Scene(Scene_Ref scene);

    void Ini_Label(MainWindow* parent, int x, int y, int w, int h, QString default_label_url, QString enter_label_url);

private:
    Ui::MainWindow *ui;

    QList<PLabel*> _plabel_list;
};
#endif // MAINWINDOW_H

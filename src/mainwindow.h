#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "herobutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString nickname,QWidget *parent = nullptr);
    ~MainWindow();
    QString person_name;
public slots:
    void pressButton();

private:
    QList<HeroButton*>list_buttons;
    void generate_ButtonList();
    void changeLabels();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

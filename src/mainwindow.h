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
    int red_counter = 8;
    int blue_counter = 9;
public slots:
    void pressButton();
    void pressAnswers();

private:
    QList<HeroButton*>list_buttons;
    QList<HeroButton*>list_dial;
    void generate_ButtonList();
    void changeLabels();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#ifndef GREETINGWINDOW_H
#define GREETINGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "mainwindow.h"

class GreetingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GreetingWindow(QWidget *parent = nullptr);
    void setWidgets();

private:
    QPushButton *newgame_but;
    QPushButton *exit_but;
//    MainWindow mainwind;
    QLineEdit *line_name;

public slots:
    void exit_app();
    void start_game();

};

#endif // GREETINGWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QString nickname, QWidget *parent) : QMainWindow(parent),person_name(nickname),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DotaNames");
    changeLabels();
    generate_ButtonList();
    //start player = 9  ; second = 8; skip turn - 7;; lose = 1;
    int row = 0;
    int col = 0;
    for(HeroButton *but : list_buttons)
    {
        if(col == 5)
        {
            row++;
            col = 0;
        }

        ui->gridLayout->addWidget(but,row,col);
        col++;
        connect(but, SIGNAL(clicked()), this, SLOT(pressButton()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pressButton()
{
    HeroButton *but = qobject_cast<HeroButton*>(sender());
    but->changeColor();
}

void MainWindow::generate_ButtonList()
{
    for(int i = 1; i <= 25; i++)
    {
        HeroButton *but = new HeroButton;
        list_buttons.append(but);
    }
}

void MainWindow::changeLabels()
{
    ui->label_blue->setStyleSheet("background-color : blue;");
    ui->label_red->setStyleSheet("background-color : red;");
}


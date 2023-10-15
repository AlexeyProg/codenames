#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QString nickname, QWidget *parent) : QMainWindow(parent),person_name(nickname),
        ui(new Ui::MainWindow)
{
    //new game nado sdelat'
    ui->setupUi(this);
    this->setWindowTitle("DotaNames");
    changeLabels();
    generate_ButtonList();
    //start player = 9  ; second = 8; skip turn - 7;; lose = 1;
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pressAnswers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pressButton()
{
    HeroButton *but = qobject_cast<HeroButton*>(sender());
    but->changeColor();
    if(but->own_color == "red")
    {
        red_counter--;
        ui->label_red->setText(QString::number(red_counter));
        if(red_counter == 0)
        {
            QMessageBox::information(this,"Congratulations!", "Red team win!", QMessageBox::Ok);
            for(auto *it : list_buttons)
            {
                it->setStyleSheet(QString("background-color : %1; color : green;").arg(it->own_color));
            }
        }
    }
    else if(but->own_color == "blue")
    {
        blue_counter--;
        ui->label_blue->setText(QString::number(blue_counter));
        if(blue_counter == 0)
        {
            QMessageBox::information(this,"Congratulations!", "Blue team win!", QMessageBox::Ok);
        }
    }
    else if(but->own_color == "black")
    {
        QMessageBox::warning(this, "The end", "You lose!", QMessageBox::Ok);
    }
}

void MainWindow::pressAnswers()
{
    QDialog *dial1 = new QDialog(this);
    dial1->setGeometry(0,0,700,500);
    QGridLayout *lay1 = new QGridLayout(dial1);
    int row = 0;
    int col = 0;
    for(HeroButton *but : list_buttons)
    {
        if(col == 5)
        {
            row++;
            col = 0;
        }
        QLabel *lab = new QLabel(dial1);
        QFont font;
        font.setPointSize(20);
        lab->setText(but->own_name);
        lab->setFont(font);
        lab->setAlignment(Qt::AlignCenter);
        lab->setGeometry(0,0,50,100);
        lab->setStyleSheet(QString("background-color : %1; color : green;").arg(but->own_color));
        lay1->addWidget(lab,row,col);
        col++;
    }
    dial1->show();
}

void MainWindow::generate_ButtonList()
{
    for(int i = 1; i <= 25; i++)
    {
        HeroButton *but = new HeroButton;
        list_buttons.append(but);
        list_dial.append(but);
    }
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

void MainWindow::changeLabels()
{
    QFont font;
    font.setPointSize(22);
    ui->label_blue->setFont(font);
    ui->label_red->setText(QString::number(red_counter));
    ui->label_red->setFont(font);
    ui->label_blue->setText(QString::number(blue_counter));
    ui->label_blue->setStyleSheet("background-color : blue; color : yellow;");
    ui->label_red->setStyleSheet("background-color : red; color : yellow;");
}


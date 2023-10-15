#include "greetingwindow.h"
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QMessageBox>

GreetingWindow::GreetingWindow(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(200,200,250,300);
    this->setWindowTitle("DotaNames");
    setWidgets();

    connect(exit_but, SIGNAL(clicked()), this, SLOT(exit_app()));
    connect(newgame_but, SIGNAL(clicked()), this, SLOT(start_game()));
}

void GreetingWindow::setWidgets()
{
    line_name = new QLineEdit(this);
    line_name->setPlaceholderText("Enter your nickname...");
    newgame_but = new QPushButton(this);
    newgame_but->setText("Start");
    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->setContentsMargins(20,40,20,40);

    exit_but = new QPushButton(this);
    exit_but->setText("Exit");
    QSpacerItem *spacer = new QSpacerItem(0,20,QSizePolicy::Preferred, QSizePolicy::Expanding);
    QSpacerItem *spacer_top = new QSpacerItem(0,10, QSizePolicy::Minimum, QSizePolicy::Minimum);
    lay->addWidget(line_name);
    lay->addSpacerItem(spacer_top);
    lay->addWidget(newgame_but);
    lay->addSpacerItem(spacer);
    lay->addWidget(exit_but);
}

void GreetingWindow::exit_app()
{
    this->close();
}

void GreetingWindow::start_game()
{
    if(line_name->text().isEmpty())
    {
        QMessageBox::warning(this,"Error!", "You need to select a nickname!", QMessageBox::Ok);
        return;
    }
    this->close();
    MainWindow *mainw = new MainWindow(line_name->text());
    mainw->show();
}

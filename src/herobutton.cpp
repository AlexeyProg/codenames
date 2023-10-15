#include "herobutton.h"
#include <QRandomGenerator>
#include <QFont>

static int blue_counter = 0;
static int red_counter = 0;
static int white_counter = 0;
static int black_counter = 0;


HeroButton::HeroButton()
{
    this->setMaximumHeight(50);
    this->setMaximumWidth(150);
    generateName();
    generateColor();
    QFont font;
    font.setFamily("Arial");
    this->setText(own_name.toUpper());
}

void HeroButton::generateName()
{
    int ind = QRandomGenerator::global()->bounded(list_names.size());
    own_name = list_names[ind];
}

void HeroButton::generateColor()
{
    while (true)
    {
        int ind = QRandomGenerator::global()->bounded(list_color.size());

        if (list_color[ind] == "red" && red_counter < 9)
        {
            own_color = list_color[ind];
            red_counter++;
            break;
        }
        else if (list_color[ind] == "blue" && blue_counter < 9)
        {
            own_color = list_color[ind];
            blue_counter++;
            break;
        }
        else if (list_color[ind] == "white" && white_counter < 7)
        {
            own_color = list_color[ind];
            white_counter++;
            break;
        }
        else if (list_color[ind] == "black" && black_counter < 1)
        {
            own_color = list_color[ind];
            black_counter++;
            break;
        }
    }
}

void HeroButton::changeColor()
{
    if (own_color == "red")
    {
       setStyleSheet("background-color: red; color : yellow;");
    }
    else if (own_color == "blue")
    {
       setStyleSheet("background-color: blue; color : yellow;");
    }
    else if (own_color == "white")
    {
        setStyleSheet("background-color: grey; color : yellow;");
    }
    else if (own_color == "black")
    {
        setStyleSheet("background-color: black; color : yellow;");
    }
}

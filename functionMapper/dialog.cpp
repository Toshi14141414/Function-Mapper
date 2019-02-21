#include "dialog.h"
#include "ui_dialog.h"
#include <QtGui>
#include <QHBoxLayout>
#include "mathfunction.h"
#include "cmath"
#include "string"
#include "iostream"
#include "sstream"


#define pi 3.14159;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{

        func = new mathFunction;


    lineEdit = new QLineEdit;

    resultButton = new QPushButton(tr("确定"));
    resultButton->setDefault(true);


    closeButton = new QPushButton(tr("关闭"));

    connect(resultButton,SIGNAL(clicked()),this,SLOT(resultClicked()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));


    horizontalSliders = new QSlider(Qt::Horizontal);
    verticalSliders = new QSlider(Qt::Vertical);
    horizontalSliders->setMinimum(10);
    horizontalSliders->setMaximum(100);
    horizontalSliders->setValue(10);

    verticalSliders->setMaximum(100);
    verticalSliders->setMinimum(10);
    verticalSliders->setValue(10);

    connect(horizontalSliders, SIGNAL(valueChanged(int)), this, SLOT(changeXscale(int)));
    connect(verticalSliders, SIGNAL(valueChanged(int)), this, SLOT(changeYscale(int)));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(lineEdit);


    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);

    leftLayout->addStretch();
    leftLayout->addWidget(horizontalSliders);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(resultButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(verticalSliders);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);

    resize(800,600);

}

void Dialog::changeXscale(int value)
{
    Xrange = value;
    info = 1;
    QWidget::update();
}

void Dialog::changeYscale(int value)
{
    Yrange = value;
    info = 1;
    QWidget::update();
}

Dialog::~Dialog()
{

}


void Dialog::resultClicked()
{


    (func->rawFunction) = (lineEdit->text().toStdString());
    func->generateFunction();
    info = 1;
    QWidget::update();

}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(50,300,650,300);
    painter.drawLine(350,100,350,500);
    int i;
    painter.drawLine(645,295,650,300);
    painter.drawLine(650,300,645,305);
    painter.drawLine(345,105,350,100);
    painter.drawLine(350,100,355,105);
    for(i = 0; i<=10;i++)
    {
        painter.drawLine(100+i*50,300,100+i*50,310);
        if(i == 5)
        {
            painter.drawText(55+i*34,310
                             ,65+i*33,320,Qt::AlignHCenter|Qt::AlignTop,QString::number(0));
            continue;
        }
        painter.drawText(60+i*34,310,70+i*33,320,Qt::AlignHCenter|Qt::AlignTop,QString::number((-250.0+i*50)/Xrange,'f',2));

    }
    for(i = 0;i<=8;i++)
    {
        painter.drawLine(350,140+i*40,360,140+i*40);
        if(i == 4)
                continue;
        painter.drawText(208,135+i*40,218,145+i*40,Qt::AlignHCenter|Qt::AlignTop,QString::number((160.0-i*40)/Yrange,'f',2));
    }


    if(info == 0)
        return;
    else
        if(info == 1)
        {
            int i = 0;
            double x = -250/Xrange;
            int count = 20000/Xrange;
            double step = 0.025;
            for(;count >= 0; count--)
            {

                    std::vector<double> tmp1;
                    std::vector<double> tmp2;
                    tmp1.push_back(x);
                    x+=step;
                    tmp2.push_back(x);
                    painter.drawLine((x-step)*Xrange+350,(-func->get(tmp1))*Yrange+300,(x)*Xrange+350,(-func->get(tmp2))*Yrange+300);
            }

         }


}

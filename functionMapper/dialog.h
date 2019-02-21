#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "mathfunction.h"

#include <QSlider>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    mathFunction *func;
    int info = 0;
    int Xrange = 1;
    int Yrange = 1;


private:

    QSlider *horizontalSliders;
    QSlider *verticalSliders;

    QLineEdit *lineEdit;


    QPushButton *resultButton;
    QPushButton *closeButton;

private slots:
    void resultClicked();


    void changeXscale(int );
    void changeYscale(int );
    void paintEvent(QPaintEvent *event);
};

#endif // DIALOG_H

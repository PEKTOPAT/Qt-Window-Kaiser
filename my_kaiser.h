#ifndef MY_KAISER_H
#define MY_KAISER_H

#include <QMainWindow>
#include <QDebug>
#include <QtMath>

namespace Ui {
class my_kaiser;
}

class my_kaiser : public QMainWindow
{
    Q_OBJECT

public:
    explicit my_kaiser(QWidget *parent = 0);
    QVector<double> kaiser(double NumSample, QVector<double> Beta);
    QVector<double> getBessel(QVector<double> x);

    ~my_kaiser();


private:
    Ui::my_kaiser *ui;

};

#endif

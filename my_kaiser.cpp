#include "my_kaiser.h"
#include "ui_my_kaiser.h"

my_kaiser::my_kaiser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::my_kaiser)
{
    ui->setupUi(this);
}

my_kaiser::~my_kaiser()


{
    delete ui;
}

QVector <double>  my_kaiser::kaiser(double NumSample, QVector <double> Beta)
{
    double M = (NumSample - 1) / 2;
    QVector <double> n;
    for (double i = -M; i <= M; i++)
    {
        n.append(i);
    }
    QVector <double> alpha;

    for(int i = 0; i < NumSample; i++)
    {
        alpha.append(Beta[0] * sqrt(1 - qPow((n[i] / M),2)));
    }
    QVector <double> num = getBessel(alpha);
    QVector <double> denom = getBessel(Beta);
    qDebug() << "_h__" << denom.size();
    QVector <double> windowCoef;
            for (int i = 0; i < num.size(); i++)
            {
               windowCoef.append(num[i] / denom[0]);
            }
            qDebug() << windowCoef[100] << windowCoef[101] << windowCoef[102];
    return windowCoef;
}

QVector <double> my_kaiser::getBessel(QVector <double> x)
{
    bool flag;
    if(x.size() == 1) flag = true;
    else flag = false;
    QVector <double> sum;
    for(int i = 0; i < x.size(); i++)
    {
        sum.append(1);
    }
    double factorial;
    for (int k = 1; k <= 100; k++)
    {
        factorial = 1;
        for (int i = 1; i <= k; i++)
        {
            factorial = factorial * i;
        }
        if(flag) sum[0] = sum[0] + qPow(((1.0/factorial) * qPow((x[0]/2), k)), 2);
        else
        {
            for(int i = 0; i < x.size(); i++)
            {
                sum[i] = sum[i] + qPow((((1/factorial) * qPow((x[i] / 2), k))), 2);
            }
        }
    }
    return sum;
}

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void digit_clicked();

    void on_btnDot_clicked();

    void on_btnClear_clicked();

    void on_btnPlus_clicked();

private:
    Ui::Widget  *ui;
private:
//    double sunInMemory;//内存中保存的值
    double sumSoFar;//积累到目前的结果，按=之后会计算最新值并且显示在屏幕上。按C会清零
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperator;
};

#endif // WIDGET_H

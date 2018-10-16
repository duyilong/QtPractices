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

private:
    Ui::Widget *ui;
    QString strShow;
    double   result;
    QString    str1;
    QString    str2;
    int      param1;
    int      param2;
};

#endif // WIDGET_H

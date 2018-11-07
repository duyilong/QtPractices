#include "widget.h"
#include "ui_widget.h"
#include "QLineEdit"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 绑定数字键和槽函数，为方便，将10个键绑定到一个槽函数
    connect(ui->btn0,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn1,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn2,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn3,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn4,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn5,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn6,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn7,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn8,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
    connect(ui->btn9,SIGNAL(clicked(bool)),this,SLOT(digit_clicked()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnDot_clicked()
{

}

void Widget::on_btnClear_clicked()
{// 清空显示的字符和计算用的字符
    strShow = "";
    str1 = "";
    str2 = "";
    param1 = 0.0;
    param2 = 0.0;
    ui->lineEdit->setText(strShow);
}

void Widget::paramUpdate(QString str1, QString str2)
{
    param1 = str1.toDouble();
    double var = str2.toDouble();
    switch (lastOperation) {
    case plus:
        param1+=var;
        break;
    case minus:
        param1-=var;
        break;
    case multiply:
        param1*=var;
        break;
    case divide:
        param1/=var;
        break;
    default:
        break;
    }
}

void Widget::on_btnPlus_clicked()
{
    if(lastOperation != 0)
    {
        paramUpdate(str1,str1);
        str1 = QString("%1").arg(param1);
        str2 = "";
        strShow = str1 + "\n +  ";
        lastOperation = plus;
    }
    else
    {
        lastOperation = plus; // 计算位标志设为＋
        str1 = strShow;       // 运算数1设为当前显示的字符
        str2 = "";
        strShow += "\n +  ";      // 当前显示的字符下一行显示新的运算数
    }
}


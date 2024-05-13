


#include <string>
#include <QWidget>
#include<iostream>
#include<QString>
#include <QtCore>
#include <QtGui/QIcon>
#include <QtWidgets>
// #include <qobjectdefs.h>
// #include <qobject.h>
//#include <winsock.h>
QT_BEGIN_NAMESPACE

class task
{
public:
    QWidget *newWidget=new QWidget();//任务组件

    QCheckBox *newCheckbox=new QCheckBox();//复选框
    QLabel *newLabel=new QLabel();//标签
    QPushButton *newBottun=new QPushButton();//按钮
    QHBoxLayout *newHBoxLayout= new QHBoxLayout();//布局
    //task(QCheckBox *Checkbox,QLabel *Label,QPushButton *Bottun,QWidget *Widget,QHBoxLayout *HBoxLayout)
    void setup_task()
    {
        this->newHBoxLayout->addWidget(this->newCheckbox);
        this->newHBoxLayout->addWidget(this->newLabel);
        this->newHBoxLayout->addWidget(this->newBottun);
        QObject::connect(newBottun, SIGNAL(clicked()), newWidget, SLOT(deleteLater()));//给删除按钮添加删除功能
        this->newHBoxLayout->setAlignment(Qt::AlignTop);//置顶（好像没用就是了）
        this->newWidget->setLayout(newHBoxLayout);
    }
    void setLabel_contain(QString task_contain)
    {
        newLabel->setText(task_contain);
    }

};


// task::task(QCheckBox *Checkbox,QLabel *Label,QPushButton *Bottun,QWidget *Widget,QHBoxLayout *HBoxLayout)
// {
//     HBoxLayout.addWidget(newCheckbox);
//     //Checkbox.
// }
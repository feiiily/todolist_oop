#include "test.h"
#include "ui_test.h"
#include <iostream>
#include <QString>
#include <string>
#include "class.cpp"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;


void read_data()
{
    std::ifstream file("task_data.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
    }

    // 从文件流中解析JSON
    json j;
    file >> j;

    // 读取JSON中的数据
    json data = j["data"];
    for (const auto& item : data) {
        bool checked = item["checked"];
        std::string contain = item["contain"];

        
    }
}


test::test(QWidget *parent)
    : QWidget(parent), ui(new Ui::test)
{
    ui->setupUi(this);
    connect(ui->normal, SIGNAL(clicked()), this, SLOT(showNormal())); // 点击normal按钮，显示normal窗口
}

test::~test()
{
    delete ui;
}

std::string QStringtoString(QString qstr)
{
    QByteArray byteArr = qstr.toLocal8Bit();
    std::string str = std::string(byteArr); // QString转string
    return str;
}

//添加任务按钮事件
void test::on_pushButton_add_clicked()
{
    QString qstr = ui->textEdit_add_task->toPlainText();//获取输入框内的内容
    QByteArray byteArr = qstr.toLocal8Bit();//避免中文乱码
    //std::string str = std::string(byteArr); // QString转string
    //std::cout << str;
    //ui->label->setText(qstr); // 显示在label上

    // task *temp;
    // temp->setup_task();
    // temp->setLabel_contain(byteArr);
    // std::cout<<temp->newLabel.toPlainText();
    // ui->tasks->setLayout(temp->newHBoxLayout);

    QWidget *newWidget=new QWidget();//任务组件

    QCheckBox *newCheckbox=new QCheckBox();//复选框
    QLabel *newLabel=new QLabel();//标签
    QPushButton *newBottun=new QPushButton();//按钮
    QHBoxLayout *newHBoxLayout= new QHBoxLayout();//布局
    newHBoxLayout->addWidget(newCheckbox);
    connect(newCheckbox, SIGNAL(isChecked()), newWidget, SLOT(deleteLater()));//给checkbox添加勾选功能
    newHBoxLayout->addWidget(newLabel);
    newHBoxLayout->addWidget(newBottun);
    connect(newBottun, SIGNAL(clicked()), newWidget, SLOT(deleteLater()));//给删除按钮添加删除功能
    newHBoxLayout->setAlignment(Qt::AlignTop);//置顶（好像没用就是了）
    newWidget->setLayout(newHBoxLayout);
    newLabel->setText(byteArr);
    ui->tasks->layout()->addWidget(newWidget);
}

// void checkbox_test(QWidget *p){
//     if(p->){
//         //ui->done_label->setText("已完成：");
//         layout()->removeItem(ui->task1->layout());
//         ui->task_done->layout()->addWidget(ui->tasks->findChild<QWidget *>(QStringtoString(focusWidget()->parent()->objectName())));
//     }

// }

void test::on_checkBox_clicked()
{

    if (ui->checkBox->isChecked())//若checkbox勾选上
    {
        ui->done_label->setText("已完成：");
        // ui->task_done->layout()->addWidget(ui->tasks->findChild<QWidget *>(this->parentWidget()->objectName().toStdString().c_str())); // Change the argument type of findChild to match the type of the widget you are searching for
        // std::cout << QStringtoString(this->parentWidget()->objectName()); // Use toStdString() to convert QString to std::string

        // std::cout << QStringtoString(this->objectName());                    // 显示test
        // std::cout << QStringtoString(focusWidget()->parent()->objectName()); // 显示当前checkbox的父窗口的名字，赢！
        layout()->removeItem(ui->task1->layout());
        ui->task_done->layout()->addWidget(ui->tasks->findChild<QWidget *>(QStringtoString(focusWidget()->parent()->objectName())));
        // std::cout << QStringtoString(ui->task1->layout()->objectName());
        // QPushButton *button5 = new QPushButton("Five");
        // QLayout *layout_temp = new QHBoxLayout();
        // layout_temp->setAlignment(Qt::AlignTop);
        // layout_temp->addWidget(button5);
        // layout()->removeItem(ui->task1->layout());
        // ui->task1->setLayout(layout_temp);

        // std::cout << QStringtoString(ui->task1->layout()->objectName());
    }
    else
    {
        // ui->task_done->layout()->removeWidget(ui->task_done->findChild<QWidget *>(QStringtoString(focusWidget()->parent()->objectName())));
        // std::cout << QStringtoString(focusWidget()->parent()->objectName());
        layout()->removeItem(ui->task1->layout());
        ui->tasks->layout()->addWidget(ui->task_done->findChild<QWidget *>(QStringtoString(focusWidget()->parent()->objectName())));
        //QLayout *layout_temp = new QHBoxLayout();
        //layout_temp->setAlignment(Qt::AlignTop);
        //ui->task1->setLayout(layout_temp);
        // std::cout << QStringtoString(focusWidget()->parent()->objectName());
    }
}

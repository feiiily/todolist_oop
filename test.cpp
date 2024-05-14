#include "test.h"
#include "ui_test.h"
#include <iostream>
#include <QString>
#include <string>
#include "class.cpp"
#include <fstream>
#include "json.hpp"
#include "add_task_button.h"
using json = nlohmann::json;

test::test(QWidget *parent)
    : QWidget(parent), ui(new Ui::test)
{
    ui->setupUi(this);
    //重置窗口事件
    connect(ui->normal, SIGNAL(clicked()), this, SLOT(showNormal())); // 点击normal按钮，显示normal窗口
    //绑定清空事件
    connect(ui->clean_task, &QPushButton::clicked, [&](){
        QLayoutItem *child;
        while ((child = ui->verticalLayout->takeAt(0)) != nullptr) {
            if (QWidget *widget = child->widget()) {
                widget->hide();
                delete widget;
            }
            delete child;
        }
    });
    connect(ui->clean_task, &QPushButton::clicked, [&](){
        QLayoutItem *child;
        while ((child = ui->verticalLayout_3->takeAt(0)) != nullptr) {
            if (QWidget *widget = child->widget()) {
                widget->hide();
                delete widget;
            }
            delete child;
        }
    });
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
    
    add_task_button *newTaskButton = new add_task_button(this); // Assuming this code is inside a QWidget-derived class

    // Set task and text for the new task button
    newTaskButton->setTask();
    newTaskButton->connect_delete_button();
    newTaskButton->setText(qstr);
    // Add the new task button to the layout
    ui->tasks->layout()->addWidget(newTaskButton->newWidget);

}


void test::on_checkBox_clicked()
{

    if (ui->checkBox->isChecked())//若checkbox勾选上
    {
        ui->done_label->setText("已完成：");
        layout()->removeItem(ui->task1->layout());
        ui->task_done->layout()->addWidget(ui->tasks->findChild<QWidget *>(QStringtoString(focusWidget()->parent()->objectName())));
    }
    else
    {

        layout()->removeItem(ui->task1->layout());
        ui->tasks->layout()->addWidget(ui->task_done->findChild<QWidget *>(QStringtoString(focusWidget()->parent()->objectName())));

    }
}

void test::on_read_data_clicked()
{
    std::ifstream f("test.json");
    if (!f.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
    }else {
        std::cout << "File opened successfully." << std::endl;
    }

    std::cout<<"flag1"<<std::endl;
    // 从文件流中解析JSON
    json j;
    std::cout<<"flag1"<<std::endl;
    f >> j;
    
    std::cout<<"flag2"<<std::endl;
    // 读取JSON中的数据
    json data = j["data"];
    std::cout<<"flag3"<<std::endl;
    for (const auto& item : data) {
        std::cout<<"flag4"<<std::endl;
        bool checked = item["checked"];
        std::string contain = item["contain"];
        QString qstr = QString::fromStdString(contain);//获取输入框内的内容
        QByteArray byteArr = qstr.toLocal8Bit();//避免中文乱码
        if(!checked)
        {
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

    }
}


// "data":
//     [
//         {"checked":0,"contain":"json任务示例"}
//     ]

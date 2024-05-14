#include "test.h"
#include "ui_test.h"
#include <iostream>
#include <QString>
#include <string>
#include "jsoncpp/jsontool.cpp"
#include "add_task_button.h"

test::test(QWidget *parent)
    : QWidget(parent), ui(new Ui::test)
{
    ui->setupUi(this);
    ui->pushButton_add->setText("添加");
    // 重置窗口事件
    connect(ui->normal, SIGNAL(clicked()), this, SLOT(showNormal())); // 点击normal按钮，显示normal窗口
    // 绑定清空事件
    connect(ui->clean_task, &QPushButton::clicked, [&]()
            {
        QLayoutItem *child;
        while ((child = ui->verticalLayout->takeAt(0)) != nullptr) {
            if (QWidget *widget = child->widget()) {
                widget->hide();
                delete widget;
            }
            delete child;
        } });
    connect(ui->clean_task, &QPushButton::clicked, [&]()
            {
        QLayoutItem *child;
        while ((child = ui->verticalLayout_3->takeAt(0)) != nullptr) {
            if (QWidget *widget = child->widget()) {
                widget->hide();
                delete widget;
            }
            delete child;
        } });
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

// 添加任务按钮事件
void test::on_pushButton_add_clicked()
{
    QString qstr = ui->textEdit_add_task->toPlainText(); // 获取输入框内的内容
    QByteArray byteArr = qstr.toLocal8Bit();             // 避免中文乱码

    add_task_button *newTaskButton = new add_task_button(this); // Assuming this code is inside a QWidget-derived class

    // Set task and text for the new task button
    newTaskButton->setTask();
    newTaskButton->connect_delete_button();
    newTaskButton->setText(qstr);
    
    // QObject::connect(newTaskButton->newCheckbox, &QCheckBox::stateChanged, [&]()
    //                  { newTaskButton->connect_checkbox(ui->verticalLayout, ui->verticalLayout_3, newTaskButton->newWidget); });
    //newTaskButton->connect_checkbox(ui->verticalLayout, ui->verticalLayout_3, newTaskButton->newWidget);
    // Add the new task button to the layout
    ui->tasks->layout()->addWidget(newTaskButton->newWidget);
    newTaskButton->connect_checkbox(ui->verticalLayout, ui->verticalLayout_3);

}


void test::on_read_data_clicked()
{
}

// "data":
//     [
//         {"checked":0,"contain":"json任务示例"}
//     ]

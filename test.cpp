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
    ui->done_label->setText("已完成");
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

    QString tasksJsonPath = QDir("data").filePath("tasks.json");
    // 捕获应用程序退出信号，保存任务数据到 JSON 文件
    savedata2json(tasksJsonPath.toStdString());
    delete ui;
}

void test::savedata2json(const std::string &filePath)
{
    // 获取所有任务组件的数据，并保存为 JSON 数据
    QJsonObject root;
    QJsonArray dataArray;

    // 遍历所有任务组件，获取数据
    for (const QWidget *child : ui->tasks->findChildren<QWidget *>())
    { // 未完成
        QCheckBox *checkBox = child->findChild<QCheckBox *>();
        QLabel *label = child->findChild<QLabel *>();
        if (checkBox && label)
        {
            QJsonObject task;
            task["checked"] = checkBox->isChecked() ? 1 : 0;
            task["contain"] = label->text();
            dataArray.append(task);
        }
    }
    for (const QWidget *child : ui->task_done->findChildren<QWidget *>())
    { // 已完成
        QCheckBox *checkBox = child->findChild<QCheckBox *>();
        QLabel *label = child->findChild<QLabel *>();
        if (checkBox && label)
        {
            QJsonObject task;
            task["checked"] = checkBox->isChecked() ? 1 : 0;
            task["contain"] = label->text();
            dataArray.append(task);
        }
    }

    root["data"] = dataArray;

    // 写入到文件
    QFile file(QString::fromStdString(filePath));
    file.open(QIODevice::WriteOnly);
    file.write(QJsonDocument(root).toJson());
    file.close();
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
                                                         newTaskButton->setText_re(qstr);
                                                     
                                                         // QObject::connect(newTaskButton->newCheckbox, &QCheckBox::stateChanged, [&]()
                                                         //                  { newTaskButton->connect_checkbox(ui->verticalLayout, ui->verticalLayout_3, newTaskButton->newWidget); });
                                                         //newTaskButton->connect_checkbox(ui->verticalLayout, ui->verticalLayout_3, newTaskButton->newWidget);
                                                         // Add the new task button to the layout
                                                         // ui->scrollAreaWidgetContents->layout()->addWidget(newTaskButton->newWidget);
                                                         ui->tasks->layout()->addWidget(newTaskButton->newWidget);
                                                         newTaskButton->connect_checkbox(ui->verticalLayout, ui->verticalLayout_3);

                                                         /*类模板使用
                                                         // 创建一个新的任务按钮
    add_task_button2<QObject> *newTaskButton = new add_task_button2<QObject>(this);

    // 设置任务内容和按钮文字

    // 将新任务按钮添加到布局中
    ui->tasks->layout()->addWidget(newTaskButton->newWidget);
    newTaskButton->connect_checkbox(ui->verticalLayout, ui->verticalLayout_3);
*/
    
}

void test::on_read_data_clicked()
{
    checkAndCreateTasksJson();
    createTaskWidgetsFromJson("data/tasks.json", ui);
}

// "data":
//     [
//         {"checked":0,"contain":"json任务示例"}
//     ]

#ifndef ADD_TASK_BUTTON2_H
#define ADD_TASK_BUTTON2_H

#include <QPushButton>
#include "task_base.h"
#include <QWidget>
#include <QtWidgets>
#include "add_task_button.cpp"


// 模板类
template <typename T>
class add_task_button2 : public TaskBase
{
     
public:
    explicit add_task_button2(QObject *parent = nullptr) : TaskBase(parent)
    {
    }

    QWidget *newWidget = new QWidget();             // 任务组件
    QCheckBox *newCheckbox = new QCheckBox();       // 复选框
    QLabel *newLabel = new QLabel();                // 标签
    QPushButton *newButton = new QPushButton();     // 按钮
    QHBoxLayout *newHBoxLayout = new QHBoxLayout(); // 布局

    

    void setText_re(QString str)
    {
        newLabel->setText(str);
    }; // 任务内容
    void setTask()
    {
        newCheckbox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum); // 前面是v，后面是h
        newLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        newLabel->setAlignment(Qt::AlignLeft);
        newHBoxLayout->addWidget(newCheckbox);
        newHBoxLayout->addWidget(newLabel);
        newHBoxLayout->addWidget(newButton);
        newWidget->setLayout(newHBoxLayout);

        newButton->setText("删除");
    }; // 组装
    void connect_delete_button()
    {
        connect(newButton, SIGNAL(clicked()), newWidget, SLOT(deleteLater()));
    }; // 绑定删除事件
    void connect_checkbox(QVBoxLayout *fromLayout, QVBoxLayout *toLayout)
    {
        connect(newCheckbox, &QCheckBox::stateChanged, [=]()
                { moveWidget(fromLayout, toLayout, newWidget, newCheckbox); });
    }; // 绑定复选框事件
    void read_data_json() {

    }; // 读取json中数据
    ~add_task_button2()
    {
        delete newWidget;
        delete newCheckbox;
        delete newLabel;      // 标签
        delete newButton;     // 按钮
        delete newHBoxLayout; // 布局
    };
    // 自定义信号
    void emitStateChanged(bool checked)
    {
        emit stateChanged(checked);
    }

signals:
    // 自定义信号声明
    void stateChanged(bool checked);
};
#endif // ADD_TASK_BUTTON2_H

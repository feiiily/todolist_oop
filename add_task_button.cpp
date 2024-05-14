#include "add_task_button.h"

add_task_button::add_task_button(QWidget *parent):QPushButton(parent) {}

void add_task_button::setTask()
{

    newHBoxLayout->addWidget(newCheckbox);
    newHBoxLayout->addWidget(newLabel);
    newHBoxLayout->addWidget(newBottun);
    newWidget->setLayout(newHBoxLayout);

}
void add_task_button::setText(QString str)
{
    newLabel->setText(str);
}

add_task_button::~add_task_button(){
    delete newWidget;
    delete newCheckbox;
    delete newLabel;                // 标签
    delete newBottun;     // 按钮
    delete newHBoxLayout; // 布局
}

#include <QString>

#include "add_task_button.h"
#include <string>
#include <iostream>

#include "test.h"
#include "ui_test.h"
#include "test.cpp"

add_task_button::add_task_button(QWidget *parent) : QPushButton(parent)
{
}

void add_task_button::setTask()
{
    newCheckbox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);//前面是h，后面是v
    // newLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
    // newLabel->setAlignment(Qt::AlignLeft);
    newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    newHBoxLayout->addWidget(newCheckbox);
    newHBoxLayout->addWidget(newLabel);
    newHBoxLayout->addWidget(newButton);
    newWidget->setLayout(newHBoxLayout);

    newButton->setText("删除");
}
void add_task_button::setText_re(QString str)
{
    newLabel->setText(str);
}

void add_task_button::connect_delete_button()
{
    connect(newButton, SIGNAL(clicked()), newWidget, SLOT(deleteLater())); // 给删除按钮添加删除功能
}

void moveWidget(QVBoxLayout *fromLayout, QVBoxLayout *toLayout, QWidget *fromWidget, QCheckBox *checkbox)
{
    if (checkbox->isChecked())
    {
        fromLayout->removeWidget(fromWidget);
        toLayout->addWidget(fromWidget);
    }
    else
    {
        toLayout->removeWidget(fromWidget);
        fromLayout->addWidget(fromWidget);
    }
}

void add_task_button::connect_checkbox(QVBoxLayout *fromLayout, QVBoxLayout *toLayout)
{
    connect(newCheckbox, &QCheckBox::stateChanged, [=]()
            { moveWidget(fromLayout, toLayout, newWidget, newCheckbox); });
}

void add_task_button::read_data_json()
{
}

add_task_button::~add_task_button()
{
    delete newWidget;
    delete newCheckbox;
    delete newLabel;      // 标签
    delete newButton;     // 按钮
    delete newHBoxLayout; // 布局
}

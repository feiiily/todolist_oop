#include "add_task_button.h"
#include "test.h"
#include "ui_test.h"
#include "jsoncpp/jsontool.cpp"
add_task_button::add_task_button(QWidget *parent):QPushButton(parent) {}

void add_task_button::setTask()
{

    newHBoxLayout->addWidget(newCheckbox);
    newHBoxLayout->addWidget(newLabel);
    newHBoxLayout->addWidget(newButton);
    newWidget->setLayout(newHBoxLayout);

}
void add_task_button::setText(QString str)
{
    newLabel->setText(str);
}


void add_task_button::connect_delete_button()
{
    connect(newButton, SIGNAL(clicked()), newWidget, SLOT(deleteLater()));//给删除按钮添加删除功能
}

void add_task_button::connect_checkbox()
{
    // if (newCheckbox->isChecked())//若checkbox勾选上
    // {
    //     // ui->done_label->setText("已完成：");
    //     layout()->removeItem(ui->task1->layout());
    //     ui->task_done->layout()->addWidget(ui->tasks->findChild<QWidget *>(QStringtoString(focusWidget()->parent()->objectName())));
    // }
    // else
    // {

    //     layout()->removeItem(ui->task1->layout());
    //     ui->tasks->layout()->addWidget(ui->task_done->findChild<QWidget *>(QStringtoString(focusWidget()->parent()->objectName())));

    // }
}

void add_task_button::read_data_json()
{
    
}


add_task_button::~add_task_button(){
    delete newWidget;
    delete newCheckbox;
    delete newLabel;                // 标签
    delete newButton;     // 按钮
    delete newHBoxLayout; // 布局
}

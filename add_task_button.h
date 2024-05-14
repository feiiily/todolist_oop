#ifndef ADD_TASK_BUTTON_H
#define ADD_TASK_BUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QtWidgets>

class add_task_button : public QPushButton
{
    Q_OBJECT
public:
    add_task_button(QWidget *parent=nullptr);
    QWidget *newWidget = new QWidget();             // 任务组件
    QCheckBox *newCheckbox = new QCheckBox();       // 复选框
    QLabel *newLabel = new QLabel();                // 标签
    QPushButton *newBottun = new QPushButton();     // 按钮
    QHBoxLayout *newHBoxLayout = new QHBoxLayout(); // 布局
    void setText(QString str);
    void setTask();
    ~add_task_button();

};

#endif // ADD_TASK_BUTTON_H

#ifndef TASK_BASE_H
#define TASK_BASE_H

#include <QObject>

// 非模板基类
class TaskBase : public QObject {
    Q_OBJECT
public:
    explicit TaskBase(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~TaskBase() {}

signals:
    // 需要的信号声明
};

#endif // TASK_BASE_H

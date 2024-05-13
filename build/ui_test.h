/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *firstpage;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *input;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_add_task;
    QPushButton *pushButton_add;
    QFrame *line;
    QLabel *label_2;
    QGroupBox *tasks;
    QVBoxLayout *verticalLayout_2;
    QWidget *task1;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *task_done;
    QVBoxLayout *verticalLayout_3;
    QLabel *done_label;
    QGroupBox *tools;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clean;
    QPushButton *normal;

    void setupUi(QWidget *test)
    {
        if (test->objectName().isEmpty())
            test->setObjectName("test");
        test->setEnabled(true);
        test->resize(484, 595);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(test->sizePolicy().hasHeightForWidth());
        test->setSizePolicy(sizePolicy);
        test->setMinimumSize(QSize(381, 477));
        test->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("image/calendarSolid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        test->setWindowIcon(icon);
        verticalLayout_5 = new QVBoxLayout(test);
        verticalLayout_5->setObjectName("verticalLayout_5");
        firstpage = new QGroupBox(test);
        firstpage->setObjectName("firstpage");
        verticalLayout_4 = new QVBoxLayout(firstpage);
        verticalLayout_4->setObjectName("verticalLayout_4");
        input = new QGroupBox(firstpage);
        input->setObjectName("input");
        horizontalLayout_3 = new QHBoxLayout(input);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        textEdit_add_task = new QTextEdit(input);
        textEdit_add_task->setObjectName("textEdit_add_task");
        textEdit_add_task->setMaximumSize(QSize(1677215, 50));
        QFont font;
        font.setPointSize(18);
        font.setBold(false);
        textEdit_add_task->setFont(font);
        textEdit_add_task->setMouseTracking(false);
        textEdit_add_task->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(textEdit_add_task);

        pushButton_add = new QPushButton(input);
        pushButton_add->setObjectName("pushButton_add");
        sizePolicy.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy);
        pushButton_add->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(pushButton_add);


        verticalLayout_4->addWidget(input, 0, Qt::AlignTop);

        line = new QFrame(firstpage);
        line->setObjectName("line");
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_4->addWidget(line, 0, Qt::AlignTop);

        label_2 = new QLabel(firstpage);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);

        verticalLayout_4->addWidget(label_2);

        tasks = new QGroupBox(firstpage);
        tasks->setObjectName("tasks");
        sizePolicy.setHeightForWidth(tasks->sizePolicy().hasHeightForWidth());
        tasks->setSizePolicy(sizePolicy);
        tasks->setMinimumSize(QSize(30, 30));
        verticalLayout_2 = new QVBoxLayout(tasks);
        verticalLayout_2->setObjectName("verticalLayout_2");
        task1 = new QWidget(tasks);
        task1->setObjectName("task1");
        sizePolicy.setHeightForWidth(task1->sizePolicy().hasHeightForWidth());
        task1->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(task1);
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox = new QCheckBox(task1);
        checkBox->setObjectName("checkBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);
        checkBox->setMinimumSize(QSize(0, 0));
        checkBox->setSizeIncrement(QSize(0, 0));
        checkBox->setBaseSize(QSize(0, 0));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 15px;\n"
"     height: 15px;\n"
"}"));
        checkBox->setIconSize(QSize(20, 12));

        horizontalLayout->addWidget(checkBox);

        label = new QLabel(task1);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(task1);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/delete.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addWidget(task1, 0, Qt::AlignTop);


        verticalLayout_4->addWidget(tasks);

        task_done = new QGroupBox(firstpage);
        task_done->setObjectName("task_done");
        verticalLayout_3 = new QVBoxLayout(task_done);
        verticalLayout_3->setObjectName("verticalLayout_3");
        done_label = new QLabel(task_done);
        done_label->setObjectName("done_label");

        verticalLayout_3->addWidget(done_label);


        verticalLayout_4->addWidget(task_done);

        tools = new QGroupBox(firstpage);
        tools->setObjectName("tools");
        horizontalLayout_2 = new QHBoxLayout(tools);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        clean = new QPushButton(tools);
        clean->setObjectName("clean");

        horizontalLayout_2->addWidget(clean);

        normal = new QPushButton(tools);
        normal->setObjectName("normal");

        horizontalLayout_2->addWidget(normal);


        verticalLayout_4->addWidget(tools);


        verticalLayout_5->addWidget(firstpage);


        retranslateUi(test);

        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QWidget *test)
    {
        test->setWindowTitle(QCoreApplication::translate("test", "Form", nullptr));
        firstpage->setTitle(QString());
        input->setTitle(QString());
        textEdit_add_task->setHtml(QCoreApplication::translate("test", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\346\255\244\345\244\204\346\267\273\345\212\240\344\273\273\345\212\241</p></body></html>", nullptr));
        pushButton_add->setText(QCoreApplication::translate("test", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QCoreApplication::translate("test", "\344\273\273\345\212\241\345\210\227\350\241\250", nullptr));
        tasks->setTitle(QString());
        checkBox->setText(QString());
        label->setText(QCoreApplication::translate("test", "\344\273\273\345\212\2411", nullptr));
        pushButton->setText(QString());
        task_done->setTitle(QString());
        done_label->setText(QString());
        tools->setTitle(QString());
        clean->setText(QCoreApplication::translate("test", "\346\270\205\347\251\272", nullptr));
        normal->setText(QCoreApplication::translate("test", "\351\207\215\347\275\256\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H

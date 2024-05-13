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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test
{
public:
    QGridLayout *gridLayout_6;
    QGroupBox *firstpage;
    QGridLayout *gridLayout_5;
    QGroupBox *tasks;
    QGridLayout *gridLayout_3;
    QWidget *task1;
    QGridLayout *gridLayout;
    QLabel *label;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QGroupBox *input;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit_add_task;
    QPushButton *pushButton_add;
    QFrame *line;
    QGroupBox *tools;
    QGridLayout *gridLayout_2;
    QPushButton *normal;
    QPushButton *pushButton_3;
    QPushButton *max;
    QGroupBox *task_done;
    QGridLayout *gridLayout_7;
    QLabel *done_label;

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
        gridLayout_6 = new QGridLayout(test);
        gridLayout_6->setObjectName("gridLayout_6");
        firstpage = new QGroupBox(test);
        firstpage->setObjectName("firstpage");
        gridLayout_5 = new QGridLayout(firstpage);
        gridLayout_5->setObjectName("gridLayout_5");
        tasks = new QGroupBox(firstpage);
        tasks->setObjectName("tasks");
        sizePolicy.setHeightForWidth(tasks->sizePolicy().hasHeightForWidth());
        tasks->setSizePolicy(sizePolicy);
        tasks->setMinimumSize(QSize(30, 30));
        gridLayout_3 = new QGridLayout(tasks);
        gridLayout_3->setObjectName("gridLayout_3");
        task1 = new QWidget(tasks);
        task1->setObjectName("task1");
        sizePolicy.setHeightForWidth(task1->sizePolicy().hasHeightForWidth());
        task1->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(task1);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(task1);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

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

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        pushButton = new QPushButton(task1);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/delete.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);


        gridLayout_3->addWidget(task1, 0, 0, 1, 1, Qt::AlignTop);


        gridLayout_5->addWidget(tasks, 2, 0, 1, 1);

        input = new QGroupBox(firstpage);
        input->setObjectName("input");
        gridLayout_4 = new QGridLayout(input);
        gridLayout_4->setObjectName("gridLayout_4");
        textEdit_add_task = new QTextEdit(input);
        textEdit_add_task->setObjectName("textEdit_add_task");
        textEdit_add_task->setMaximumSize(QSize(1677215, 50));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        textEdit_add_task->setFont(font1);

        gridLayout_4->addWidget(textEdit_add_task, 0, 0, 1, 1);

        pushButton_add = new QPushButton(input);
        pushButton_add->setObjectName("pushButton_add");
        sizePolicy.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy);
        pushButton_add->setMaximumSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_add, 0, 1, 1, 1);


        gridLayout_5->addWidget(input, 0, 0, 1, 1, Qt::AlignTop);

        line = new QFrame(firstpage);
        line->setObjectName("line");
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_5->addWidget(line, 1, 0, 1, 1, Qt::AlignTop);

        tools = new QGroupBox(firstpage);
        tools->setObjectName("tools");
        gridLayout_2 = new QGridLayout(tools);
        gridLayout_2->setObjectName("gridLayout_2");
        normal = new QPushButton(tools);
        normal->setObjectName("normal");

        gridLayout_2->addWidget(normal, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(tools);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);

        max = new QPushButton(tools);
        max->setObjectName("max");

        gridLayout_2->addWidget(max, 0, 1, 1, 1);


        gridLayout_5->addWidget(tools, 4, 0, 1, 1);

        task_done = new QGroupBox(firstpage);
        task_done->setObjectName("task_done");
        gridLayout_7 = new QGridLayout(task_done);
        gridLayout_7->setObjectName("gridLayout_7");
        done_label = new QLabel(task_done);
        done_label->setObjectName("done_label");

        gridLayout_7->addWidget(done_label, 0, 0, 1, 1);


        gridLayout_5->addWidget(task_done, 3, 0, 1, 1);


        gridLayout_6->addWidget(firstpage, 0, 0, 1, 1);


        retranslateUi(test);

        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QWidget *test)
    {
        test->setWindowTitle(QCoreApplication::translate("test", "Form", nullptr));
        firstpage->setTitle(QString());
        tasks->setTitle(QString());
        label->setText(QCoreApplication::translate("test", "\344\273\273\345\212\2411", nullptr));
        checkBox->setText(QString());
        pushButton->setText(QString());
        input->setTitle(QString());
        textEdit_add_task->setHtml(QCoreApplication::translate("test", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI';\">\346\267\273\345\212\240\344\273\273\345\212\241</span></p></body></html>", nullptr));
        pushButton_add->setText(QCoreApplication::translate("test", "\346\267\273\345\212\240", nullptr));
        tools->setTitle(QString());
        normal->setText(QCoreApplication::translate("test", "\351\207\215\347\275\256\347\252\227\345\217\243", nullptr));
        pushButton_3->setText(QCoreApplication::translate("test", "\346\234\200\345\260\217\345\214\226", nullptr));
        max->setText(QCoreApplication::translate("test", "\346\234\200\345\244\247\345\214\226", nullptr));
        task_done->setTitle(QString());
        done_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H

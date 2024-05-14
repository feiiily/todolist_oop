#ifndef TEST_H
#define TEST_H

#include <QWidget>

namespace Ui {
class test;
}

class test : public QWidget
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = nullptr);
    void savedata2json(const std::string &filePath);
    ~test();

private slots:
    void on_pushButton_add_clicked();
    void on_read_data_clicked();

private:
    Ui::test *ui;
};

#endif // TEST_H

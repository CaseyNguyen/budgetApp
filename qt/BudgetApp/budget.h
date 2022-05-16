#ifndef BUDGET_H
#define BUDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Budget; }
QT_END_NAMESPACE

class Budget : public QMainWindow
{
    Q_OBJECT

public:
    Budget(QWidget *parent = nullptr);
    ~Budget();

private:
    Ui::Budget *ui;
};
#endif // BUDGET_H

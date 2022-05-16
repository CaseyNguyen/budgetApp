#include "budget.h"
#include "./ui_budget.h"

Budget::Budget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Budget)
{
    ui->setupUi(this);
}

Budget::~Budget()
{
    delete ui;
}


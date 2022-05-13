#include "budget.h"

// Default Constructor
Budget::Budget(){
    budgetNum = 3;
    pctBudget = new float[3];
    pctBudget[0] = 50;
    pctBudget[1] = 30;
    pctBudget[2] = 20;
}

int Budget::getNum(){
    return budgetNum;
}
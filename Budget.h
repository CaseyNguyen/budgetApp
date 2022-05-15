// Casey Nguyen
// budget.h
// Created April 20th, 2022

#ifndef BUDGETAPP_BUDGET_H
#define BUDGETAPP_BUDGET_H
#include <iostream>
#include <iomanip>
#include <sstream>

class Budget{
    unsigned int budgetCount; // # of budget-type variables (income, 3-expenses).
    double* budgetSum; // Stores the sum of incomes and expenses (4 variables).
    // 0 - Income | 1 - Needs | 2 - Wants | 3 - Saves
    double* budgetPct; // Stores percents income should be divided into.
    // 0 - Needs | 1 - Wants | 2 - Saves
    std::string roundString(double); // Rounds any input two decimal places (as string).
    double roundVal(double); // Ditto (see above), but returns as decimal.
public:
    Budget(); // Null constructor: 50/30/20 budget created.
    ~Budget(); // Destructor: deallocates budgetSum and budgetPct.
    std::string showBudget();
    // Allows the user to retrieve the current budget.
    void addIncome(double);
    // Adds positive money values (income) to the budget.
    // pre: cashVal is a positive double -> throws exception if invalid
    // post: budgetSum[0] (income) may increase by cashVal
    void addExpense(double, unsigned int);
    // Adds negative money values (expenses) to the budget.
    // pre: cashVal is a positive double; exception if not
    //      type is a whole number between 1 and 3; exception if not
    // post: budgetSum[type] (one expense type) may increase by cashVal
    void changeBudget(double[]);
    // Changes the way the money is divided.
    // pre: newBudget[] is an array of doubles that add up to 1.0; exception if not
    // post: budgetPct[] may be assigned the values in newBudget[]
};

#endif //BUDGETAPP_BUDGET_H
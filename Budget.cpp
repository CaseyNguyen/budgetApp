// Casey Nguyen
// budget.cpp
// Created April 20th, 2022

#include "budget.h"

// -- Private Functions --
std::string Budget::roundString(double rawVal){
    std::stringstream inStream;
    inStream << std::fixed << std::setprecision(2) << rawVal;
    std::string fixed = inStream.str();
    return fixed;
}

double Budget::roundVal(double rawVal){
    return (std::stod(roundString(rawVal)));
}

// -- Public Functions --
Budget::Budget(){
    budgetCount = 4;
    budgetSum = new double[budgetCount];
    for (int i = 0; i < budgetCount; i++) budgetSum[i] = 0.0;
    budgetPct = new double[budgetCount - 1];
    budgetPct[0] = 0.5;
    budgetPct[1] = 0.3;
    budgetPct[2] = 0.2;
}

Budget::~Budget(){
    delete [] budgetSum;
    delete [] budgetPct;
}

std::string Budget::showBudget(){
    std::string retSum = "Budget:\n";
    std::string addLine = "You have $";
    addLine += roundString((budgetSum[0] * budgetPct[0]) - budgetSum[1]);
    addLine += " for needs.\n";
    retSum += addLine;
    addLine = "You have $";
    addLine += roundString((budgetSum[0] * budgetPct[1]) - budgetSum[2]);
    addLine += " for wants.\n";
    retSum += addLine;
    addLine = "You have $";
    addLine += roundString((budgetSum[0] * budgetPct[2]) - budgetSum[3]);
    addLine += " for saves.\n";
    retSum += addLine;
    return retSum;
}

void Budget::addIncome(double cashVal){
    // start: guard clauses
    if (cashVal < 0.01)
        throw("Invalid cash value. Must be the absolute value.");
    // end: guard clauses
    budgetSum[0] += roundVal(cashVal);
}

void Budget::addExpense(double cashVal, unsigned int type){
    // start: guard clauses
    if (cashVal < 0.01)
        throw("Invalid cash value. Must be the absolute value.");
    if (type < 1 || type > 3)
        throw("Invalid type. Must be between 1 and 3.");
    // end: guard clauses
    if (type == 1) budgetSum[1] += roundVal(cashVal);
    else if (type == 2) budgetSum[2] += roundVal(cashVal);
    else budgetSum[3] += roundVal(cashVal);
}

void Budget::changeBudget(double newBudget[]){
    // NEED better error checking: what if newBudget is null?!?!
    // start: guard clauses
    if ((newBudget[0] + newBudget[1] + newBudget[2]) != 1.0)
        throw("Invalid budget. Must add up to 1.0.");
    // end: guard clauses
    for (int i = 0; i < budgetCount - 1; i++){
        budgetPct[i] = newBudget[i];
    }
}
// Casey Nguyen
// main.cpp
// Created May 14th, 2022

#include <iostream>
#include "Budget.h"

// inputValue
// Collects the cash value of something.
double inputValue(){
    double val = 0.0;
    std::cin >> val;
    return val;
}

// menu
// Runs the menu interface for Budge, the budget application.
void menu(){
    std::cout << "Welcome to Budge!\n";
    Budget client;
    unsigned int choice = 0;
    while (choice < 4){
        std::cout << "1. Print budget.\n" << "2. Add income.\n" << "3. Add expense.\n"
        << "4. Exit.\n";
        std::cout << "Input your selection:\n";
        std::cin >> choice;
        while (choice < 1 || choice > 5){
            std::cout << "Invalid input. Input your selection:\n";
            std::cin >> choice;
        }
        if (choice == 1) std::cout << client.showBudget(); // Print the budget.
        else if (choice == 2){ // Add income.
            try{
                std::cout << "Input your income:\n";
                client.addIncome(inputValue());
            }
            catch(char const* eMsg) {
                std::cout << eMsg << std::endl;
            }
        }
        else if (choice == 3){ // Add expense.
            try{
                std::cout << "Input the expense value:\n";
                double inVal = inputValue();
                std::cout << "Need, want, or save it?\n";
                std::cout << "Input '1' for need, '2' for want, or '3' for save: \n";
                std::cin >> choice;
                client.addExpense(inVal, choice);
                choice = 1;
            }
            catch(char const* eMsg){
                std::cout << eMsg << std::endl;
            }
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}
// main.cpp
#include "BudgetBuddy.h"
#include <iostream>
#include <string>

int main() {
    BudgetBuddy budgetBuddy;

    // Accept user inputs
    double amount;
    std::string category, date;

    std::cout << "Enter expense amount: ";
    std::cin >> amount;

    std::cout << "Enter expense category: ";
    std::cin.ignore();  // Ignore any previous newline character
    std::getline(std::cin, category);

    std::cout << "Enter expense date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    // Add expense to BudgetBuddy
    budgetBuddy.addExpense(amount, category, date);

    // Perform budget management
    budgetBuddy.manageBudget();

    // Generate and display reports
    budgetBuddy.generateReports();

    return 0;
}

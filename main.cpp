// main.cpp
#include "BudgetBuddy.h"
#include <iostream>
#include <string>

int main() {
    BudgetBuddy budgetBuddy;

    // Accept expense input
    double expenseAmount;
    std::string expenseCategory, expenseDate;

    std::cout << "Enter expense amount: ";
    std::cin >> expenseAmount;

    std::cout << "Enter expense category: ";
    std::cin.ignore();  // Ignore any previous newline character
    std::getline(std::cin, expenseCategory);

    std::cout << "Enter expense date (YYYY-MM-DD): ";
    std::getline(std::cin, expenseDate);

    // Add expense to BudgetBuddy
    budgetBuddy.addExpense(expenseAmount, expenseCategory, expenseDate);

    // Accept income input
    double incomeAmount;

    std::cout << "Enter income amount: ";
    std::cin >> incomeAmount;

    // Add income to BudgetBuddy
    budgetBuddy.addIncome(incomeAmount);

    // Accept monthly budget goals
    double monthlyBudgetGoal;

    std::cout << "Enter monthly budget goal: ";
    std::cin >> monthlyBudgetGoal;

    // Set monthly budget goal in BudgetBuddy
    budgetBuddy.setMonthlyBudgetGoal(monthlyBudgetGoal);

    // Perform budget management
    budgetBuddy.manageBudget();

    // Generate and display reports
    budgetBuddy.generateReports();

    return 0;
}


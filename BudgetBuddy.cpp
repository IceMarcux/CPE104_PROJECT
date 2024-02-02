// BudgetBuddy.cpp
#include "BudgetBuddy.h"

void BudgetBuddy::addExpense(double amount, const std::string& category, const std::string& date) {
    Expense newExpense = {amount, category, date};
    expenseList.addToFront(newExpense); // Add expense to the front of the linked list
}

void BudgetBuddy::manageBudget() {
    // Implement budget management and analytics logic here
    // You can access the expenseList and perform operations on it
}

void BudgetBuddy::generateReports() {
    // Implement report generation logic here
    // You can access the expenseList and generate reports based on it
}

// Destructor (if needed)
BudgetBuddy::~BudgetBuddy() {
    // Destructor logic, if any
}

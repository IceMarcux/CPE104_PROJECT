#include "BudgetBuddy.h"
#include <iostream>

void BudgetBuddy::addExpense(double amount, const std::string& category, const std::string& date) {
    Expense newExpense = {amount, category, date};
    expenseList.addToFront(newExpense); // Add expense to the front of the linked list
}

void BudgetBuddy::manageBudget() {
    // Assume a predefined budget goal
    const double budgetGoal = 100.0;

    // Calculate total expenses
    double totalExpenses = 0.0;
    Node<Expense>* current = expenseList.getHead();
    while (current != nullptr) {
        totalExpenses += current->data.amount;
        current = current->next;
    }

    // Check if expenses exceed the budget goal
    if (totalExpenses > budgetGoal) {
        std::cout << "Warning: Expenses exceed the budget goal!" << std::endl;
    }
}

void BudgetBuddy::generateReports() {
    // Print the list of expenses
    std::cout << "Expense Report:" << std::endl;
    expenseList.print();
}

// Destructor (if needed)
BudgetBuddy::~BudgetBuddy() {
    // Destructor logic, if any
}

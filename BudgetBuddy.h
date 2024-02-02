//BudgetBuddy.h
#pragma once

#include <iostream>
#include <string>
#include "LinkedList.h" // Include the LinkedList header

struct Expense {
    double amount;
    std::string category;
    std::string date;
};

class BudgetBuddy {
private:
    LinkedList<Expense> expenseList; // Linked list of expenses

public:
    // Function to add an expense
    void addExpense(double amount, const std::string& category, const std::string& date);

    // Function to manage the budget and perform analytics
    void manageBudget();

    // Function to generate and display reports
    void generateReports();

    // Destructor (if needed)
    ~BudgetBuddy();
};

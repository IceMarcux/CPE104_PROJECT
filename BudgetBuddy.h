// BudgetBuddy.h
#pragma once

#include <iostream>
#include <unordered_map>
#include "LinkedList.h"

// Data structures for expense records
struct Expense {
    double amount;
    std::string category;
    std::string date;
    // Add more fields as needed
};

class BudgetBuddy {
private:
    // Linked list for storing expense records
    LinkedList<Expense> expenseList;

    // Hash table for categorizing expenses
    std::unordered_map<std::string, std::vector<Expense>> expenseCategories;

    // Other variables as needed
    double totalIncome;
    double monthlyBudgetGoal;

public:
    // Function to validate and store expense input
    void addExpense(double amount, const std::string& category, const std::string& date);

    // Function to validate and store income input
    void addIncome(double amount);

    // Function to set monthly budget goal
    void setMonthlyBudgetGoal(double goal);

    // Function to perform budget management and analytics
    void manageBudget();

    // Function to generate and display reports
    void generateReports();
};

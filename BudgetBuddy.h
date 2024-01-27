#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Expense {
    double amount;
    string category;
    string date;
    // Add more fields as needed
};

struct Node {
    Expense data;
    Node* next;
};

class BudgetBuddy {
private:
    Node* expenseListHead = nullptr;

    unordered_map<string, vector<Expense>> expenseCategories;


public:
    void addExpense(double amount, const string& category, const string& date);

    void addToExpenseList(const Expense& expense);

    void addToExpenseCategories(const Expense& expense);

    void manageBudget();

    void generateReports();

    ~BudgetBuddy();
};

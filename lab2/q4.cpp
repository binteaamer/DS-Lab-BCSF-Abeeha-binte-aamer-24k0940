/*Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.*/

//code 
#include <iostream>
using namespace std;

int main() {
    int months;
    cout << "Give number of months: ";
    cin >> months;

    double* expenses = new double[months];

    for (int i = 0; i < months; i++) {
        cout << "Enter the expense for month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    char choice;
    cout << "If you want to track more months press Y, for exit press E: ";
    cin >> choice;

    if (choice == 'E' || choice == 'e') {
        cout << "Goodbye!" << endl;
        delete[] expenses;
        return 0;
    } 
    else if (choice == 'Y' || choice == 'y') {
        int extra;
        cout << "How many more months to track: ";
        cin >> extra;

        double* newexpenses = new double[months + extra];

        for (int i = 0; i < months; i++) {
            newexpenses[i] = expenses[i];
        }

        for (int i = months; i < months + extra; i++) {
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> newexpenses[i];
        }

        delete[] expenses;
        expenses = newexpenses;
        months += extra;
    } 
    else {
        cout << "Invalid choice!" << endl;
        delete[] expenses;
        return 0;
    }

    double total = 0;
    for (int i = 0; i < months; i++) {
        total += expenses[i];
    }
    double average = total / months;

    cout << "\nTotal Expenses: " << total;
    cout << "\nAverage Expenses: " << average << endl;

    delete[] expenses;
    return 0;
}

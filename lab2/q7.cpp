q7
/*A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary.*/


//code 
#include <iostream>
using namespace std;

int main() {
    int d;
    cout << "enter number of departments: ";
    cin >> d;

    int* sizes = new int[d];
    int** salaries = new int*[d];

    for (int i = 0; i < d; i++) {
    cout << "enter number of employees in department " << i << ": ";
    cin >> sizes[i];

    salaries[i] = new int[sizes[i]];
    cout << "enter salaries for department " << i << ": ";
        for (int j = 0; j < sizes[i]; j++) {
            cin >> salaries[i][j];
        }
    }

    double bestavg = -1000000000;
    int bestdept = -1;

    for (int i = 0; i < d; i++) {
        if (sizes[i] == 0) {
            cout << "department " << i << " has no employees\n";
            continue;}

        int maxsalary = salaries[i][0];
        double = salaries[i][0];

        for (int j = 1; j < sizes[i]; j++) {
            if (salaries[i][j] > maxsalary)
            maxsalary = salaries[i][j];
        sum += salaries[i][j];
        }

        double avg = (double) sum / sizes[i];
        cout << "department " << i << " -> highest salary = " << maxsalary
             << ", average salary = " << avg << endl;

        if (avg > bestavg) {
            bestavg = avg;
            bestdept = i;}
        }

    if (bestdept != -1) {
    cout << "department with maximum average salary is " 
        << bestdept << " (average = " << bestavg << ")\n";
    }

    for (int i = 0; i < d; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] sizes;

    return 0;
}

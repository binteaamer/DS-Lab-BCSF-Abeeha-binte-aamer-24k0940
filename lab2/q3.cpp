#include <iostream>
using namespace std;

int main() {
int students;
cout << "Enter number of students: ";
cin >> students;

int** marks = new int*[students];
int* courseCount = new int[students];

for (int i = 0; i < students; i++) {
        cout << "Enter number of courses for student " << i << ": ";
        cin >> courseCount[i];
        marks[i] = new int[courseCount[i]];
    }

for (int i = 0; i < students; i++) {
        for (int j = 0; j < courseCount[i]; j++) {
            cout << "Enter marks of student " << i << " for course " << j << ": ";
            cin >> marks[i][j];
        }
    }

    for (int i = 0; i < students; i++) {
        int sum = 0;
        cout << "Marks of student " << i << ": ";
        for (int j = 0; j < courseCount[i]; j++) {
            cout << marks[i][j] << " ";
            sum += marks[i][j];
        }
        float avg = (float)sum / courseCount[i];
        cout << " Average: " << avg << endl;
    }

    for (int i = 0; i < students; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courseCount;

    return 0;
}

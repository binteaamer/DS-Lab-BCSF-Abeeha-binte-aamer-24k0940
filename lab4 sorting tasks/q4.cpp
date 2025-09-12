#include<iostream>
#include<string>
using namespace std;

int priority( string dsg){
    if (dsg == "CEO") return 1;
    if (dsg == "CTO") return 2;
    if (dsg == "CFO") return 3;
    if (dsg == "VP")  return 4;
    if (dsg == "MGR") return 5;
    if (dsg == "EMP") return 6;
     return 999;}

    
    void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
    string key = arr[i];
    int keypriority = priority(key);
    int j = i - 1;

while (j >= 0 && priority(arr[j]) > keypriority) {
    arr[j + 1] = arr[j];
    j--;}
    arr[j + 1] = key;}}

int main() {
    string employees[] = {"EMP","CFO","MGR","EMP","VP","CTO","MGR","CEO"};
    int n = 8;

    cout << "Before Sorting"<<endl;
    for (int i = 0; i < n; i++)
    cout << employees[i] << " ";

    insertionSort(employees, n);

    cout << "After Sorting by Priority:\n";
    for (int i = 0; i < n; i++)
        cout << employees[i] << " ";
    cout << "\n";

    return 0;
}

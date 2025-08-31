#include <iostream>
using namespace std;
int main(){
int departments;
cout<<" enter number of departments"<<endl;
cin>>departments;

int** salaries = new int*[departments];
int* employees = new int[departments];

for(int i=0; i<departments; i++){
cout<<" enter number of employees for department "<<i<<endl;
cin>>employees[i];
salaries[i] = new int[employees[i]];

cout<<"enter salary for department "<<i<<endl;
for(int j=0; j<employees[i]; j++){
cin>>salaries[i][j];
}
}

double bestaverage=-100000000000;
int bestdepartment=-1;

for(int i=0; i<departments; i++){
if(employees[i]==0){
cout<<"department has no employee"<<endl;
continue;
}

int maxsalary = salaries[i][0];
double sum = salaries[i][0];

for(int j=1; j<employees[i]; j++){
if(salaries[i][j] > maxsalary)
maxsalary = salaries[i][j];
sum += salaries[i][j];
}

double avg = (double) sum / employees[i];
cout<<"department "<<i<<" -> highest salary = "<<maxsalary<<", average salary = "<<avg<<endl;

if(avg > bestaverage){
bestaverage = avg;
bestdepartment = i;
}
}

if(bestdepartment != -1){
cout<<"department with maximum average salary is "<<bestdepartment<<" (average = "<<bestaverage<<")\n";
}

for(int i=0; i<departments; i++){
delete[] salaries[i];
}
delete[] salaries;
delete[] employees;

return 0;
}

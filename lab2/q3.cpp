/*Task #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks.*/

//code
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
  int students;
  cout<<"enter number of students"<<endl;
  cin>> students;
 
  int**marks=new int*[students];
  int courses;
  for(int i=0; i<students; i++){
      cout<<"enter courses for student "<<i<<endl;
      cin>>courses;
      marks[i]=new int[courses];
      
  }
  for(int i=0; i < students;i++){
      for(int j=0; j<courses; j++){
          cout<<"enter marks of student "<<i<<" course "<<j<<endl;
          cin>>marks[i][j];
          
      }
  }
  
  for(int i=0; i < students;i++){
      for(int j=0; j<courses; j++){
          cout<<"marks of student "<<i<<" for course "<<j<<" "<<marks[i][j];
          
      }
      cout<<endl;
  }
    return 0;
}

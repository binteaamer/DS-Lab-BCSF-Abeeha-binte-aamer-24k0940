;q2
/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor
and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/

code:
#include <iostream>
#include <cstring>
using namespace std;

class Exam{
private:
char* Name;
char* Date;
int examscore;

public:
Exam(const char* name,const char* date,int score){
Name=new char[strlen(name)+1];
strcpy(Name,name);
Date=new char[strlen(date)+1];
strcpy(Date,date);
examscore=score;
}

~Exam(){
delete[] Name;
delete[] Date;
}

void examdetails(){
cout<<"name: "<<Name<<endl;
cout<<"date: "<<Date<<endl;
cout<<"score: "<<examscore<<endl;
}

void setName(const char* newName){
strcpy(Name,newName);
}

void setDate(const char* newDate){
strcpy(Date,newDate);
}

void setScore(int newScore){
examscore=newScore;
}
};

int main(){
Exam e1("Abeeha","2025-08-20",95);
e1.examdetails();
Exam e2=e1;
e2.examdetails(); //this again shows e1 data , shallow copy 
e1.setName("Laiba");
e1.setDate("2025-09-01");
e1.setScore(75);
cout<<"after changing e1: ";
e1.examdetails();
e2.examdetails();// shows new e1 again , shallow copy 
return 0;
}

//issue observed: when we omit the copy 
constructor and assigment operator, the shallow copy is done and this causes shared
memory issue for name and date, leading to one object change changing the other aswell
it is a double deletion issue , when destructors run. 





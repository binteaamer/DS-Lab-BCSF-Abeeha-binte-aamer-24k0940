/*Implement a stack using linked lists. Demonstrate its use with a real-life example (e.g., browser
history navigation). */
//code

#include<iostream>
using namespace std;

class node{
public:
int data;
node* next;
node(int value){
data = value;
next = nullptr;
}
};

class stackwithLL{
node* top;
public:
stackwithLL(){
top = nullptr;
}

void push(int value){
node* newnode = new node(value);
newnode->next = top;
top = newnode;
}

void pop(){
if(top == nullptr){
cout << "stack underflow" << endl;
return;
}
node* temp = top;
cout << "element popped " << top->data << endl;
top = top->next;
delete temp;
}

int peek(){
if(!top){
cout << "stack is empty" << endl;
return -1; // return int sentinel value
}
return top->data;
}

bool isempty(){
return top == nullptr;
}

void display(){
if(!top){
cout << "stack is empty" << endl;
return;
}
node* temp = top;
cout << "Stack contents: ";
while(temp){
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL" << endl;
}
};

class BrowserHistory{
stackwithLL history;
public:
void visit(int url){
cout << "Visiting: " << url << endl;
history.push(url);
}
void back(){
if(history.isempty()){
cout << "No history to go back" << endl;
return;
}
cout << "Going back from: " << history.peek() << endl;
history.pop();
if(!history.isempty()){
cout << "Current page: " << history.peek() << endl;
} else {
cout << "No current page" << endl;
}
}
void showHistory(){
history.display();
}
};

int main(){
BrowserHistory browser;
browser.visit(100); // changed url to int for simplicity
browser.visit(200);
browser.visit(300);
browser.showHistory();
browser.back();
browser.back();
browser.back();
browser.back();
return 0;
}

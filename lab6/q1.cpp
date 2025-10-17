/*Implement a stack using arrays. Support the following operations:
1. Push an element
2. Pop an element
3. Peek (top element)
4. Display stack contents*/
//code

#include <iostream>
//abeehabinteaamer 24k0940 
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;

public:
Stack(int size) {
 capacity = size;
 arr = new int[capacity];
  top = -1;
    }

  ~Stack() {
   delete[] arr;
    }

  void push(int x) {
   if (top == capacity - 1) {
   cout << "Stack Overflow\n";
   return;
        }
        arr[++top] = x;
    }

void pop() {
    if (top == -1) {
       cout << "Stack Underflow\n";
       return; }
    cout << "Popped element: " << arr[top--] << endl;}

int peek() {
  if (top == -1) {
  cout << "Stack is empty\n";
  return -1; }
        return arr[top];
    }
void display() {
if (top == -1) {
 cout << "Stack is empty\n";
  return; }
  cout << "Stack contents: ";
  for (int i = top; i >= 0; i--)
  cout << arr[i] << " ";
  cout << endl;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    return 0;
}


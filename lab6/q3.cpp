/*Implement a linear queue using arrays with the following operations:
1. Enqueue
2. Dequeue
3. Display queue contents
4. Check if queue is empty/full*/
//code


#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int capacity;

public:
Queue(int size) {
capacity = size;
  arr = new int[capacity];
front = -1;
rear = -1;}

~Queue() {
 delete[] arr; }
bool isEmpty() {
 return front == -1; }
bool isFull() {
 return (rear == capacity - 1); }
 
void enqueue(int x) {
 if (isFull()) {
  cout << "Queue Overflow\n";
 return; }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Dequeued element: " << arr[front] << endl;
        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Underflow condition

    return 0;
}

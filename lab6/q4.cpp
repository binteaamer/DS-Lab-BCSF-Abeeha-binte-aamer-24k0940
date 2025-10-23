/*Implement a circular queue using arrays. Handle the following conditions correctly:
1. Enqueue when rear wraps around
2. Dequeue when front moves ahead
3. Prevent overflow when queue is full*/

#include <iostream>
//abeehabinteaamer 24k0940
using namespace std;

class CircularQueue {
    int *arr;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;
public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIdx = 0;
        rearIdx = -1;
        count = 0;
    }
    ~CircularQueue() { delete[] arr; }
    bool isFull() { return count == capacity; }
    bool isEmpty() { return count == 0; }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rearIdx = (rearIdx + 1) % capacity;
        arr[rearIdx] = x;
        ++count;
        cout << "Enqueued: " << x << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Dequeued: " << arr[frontIdx] << endl;
        frontIdx = (frontIdx + 1) % capacity;
        --count;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue contents: ";
        int idx = frontIdx;
        for (int i = 0; i < count; ++i) {
            cout << arr[idx] << " ";
            idx = (idx + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.dequeue();
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}

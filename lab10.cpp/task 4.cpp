//array representation of min Heap, convert it to max Heap.
//code 
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < n && arr[left] > arr[largest])
largest = left;
 if (right < n && arr[right] > arr[largest])
  largest = right;
  
if (largest != i) {
swap(arr[i], arr[largest]);
heapify(arr, n, largest); }
}

void convertToMaxHeap(int arr[], int n) {
for (int i = n/2 - 1; i >= 0; i--)
heapify(arr, n, i);}

void printArray(int arr[], int n) {
for (int i = 0; i < n; i++)
cout << arr[i] << " ";
 cout << endl;}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "min heeap array: ";
    printArray(arr, n);
    convertToMaxHeap(arr, n);
    cout << "Max Heap array: ";
    printArray(arr, n);
    
    return 0;
}

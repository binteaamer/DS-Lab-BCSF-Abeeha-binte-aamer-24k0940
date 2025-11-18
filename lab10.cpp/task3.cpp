//task is to gice kth largest element 
//code 
#include <stdio.h>

void heapify_down(int arr[], int n, int i) {
int largest = i;
int l = 2*i + 1;
int r = 2*i + 2;

if(l < n && arr[l] > arr[largest]) largest = l;
  if(r < n && arr[r] > arr[largest]) largest = r;
if(largest != i) {
     int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
      heapify_down(arr, n, largest); }}
void build_max_heap(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapify_down(arr, n, i);}

int kth_largest(int arr[], int n, int k) {
 build_max_heap(arr, n);
    for(int i = 0; i < k-1; i++) {
    arr[0] = arr[n-1]; 
    n--;               
    heapify_down(arr, n, 0);
    }
    return arr[0];}

int main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    printf("%d\n", kth_largest(arr, n, k));  // Output: 23
    return 0;}


#include <iostream>
using namespace std;

int binarysearch(int arr[], int size, int target){
int left=0, right=size-1;
while(left<=right){
int mid = (left + right) / 2;
if (arr[mid] == target)
    return mid;         
    else if (arr[mid] < target)
    left = mid + 1; 
    else
    right = mid - 1;
    }
    return -1; 
}

void Sorted(int arr[], int &size, int target) {
    int i = size - 1;
    while (i >= 0 && arr[i] > target) {
        arr[i + 1] = arr[i];
        i--;
    }
     arr[i + 1] = target;
     size++;
}


int main() {
    int arr[20] = {12, 18, 24, 32, 45, 50, 66, 72}; 
    int size = 8;

    int rollNumber;
    cout << "Enter your roll number: ";
    cin >> rollNumber;

    int last2 = rollNumber % 100;
    int index = binarySearch(arr, size, last2);

    if (index != -1) {
        cout << "Employee with ID " << last2 << " found at index " << index << ".\n";
    } else {
        cout << "ID " << last2 << " not found. Inserting it at correct position...\n";
        insertInSorted(arr, size, last2);

        cout << "Updated Employee IDs: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
        
        int Index = binarySearch(arr, size, last2);
        cout << "New ID inserted at index: " << Index << endl;
    }

    return 0;
}

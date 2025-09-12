#include <iostream>
using namespace std ;
int linearsearch (int arr[] , int size, int target){
for(int i=0; i< size; i++){
if(arr[i]==target){
return i;}}
return-1;
}

int main() {
    int target;
    int n;
    cout<<"enter number of elements in array"<<endl;
    cin>>n;
    int *arr= new int[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter target value to search"<<endl;
    cin>>target;
    int index;
    
    index=linearsearch(arr,n,target);
    if (index != -1) {
        cout << "Target value " << target << " found at index " << index << "." << endl;
    } else {
   cout << "Target value " << target << " is not in the array." << endl;
    }
    delete[] arr; 
    return 0;
}

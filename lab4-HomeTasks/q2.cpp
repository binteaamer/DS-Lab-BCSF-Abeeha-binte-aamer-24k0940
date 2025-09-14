/*Write a program to implement the Bubble Sort algorithm. The program should take
an array of integers as input from the user, sort the array using bubble sort, and then
display both the unsorted and sorted arrays.*/

//code 
#include<iostream>
using namespace std;

int main(){
int n;
cout<<"enter number of elements: "<<endl;
cin>>n;
int arr[100];
    cout<<"Enter "<<n<<" integers: "<<endl;
    for(int i=0;i<n;i++)
     cin>>arr[i];

cout<<"Unsorted array: "<<endl;
for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
  
for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
    if(arr[j]>arr[j+1]){
      int temp = arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp; }}
    }

cout<<"Sorted array: "<<endl;
for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
   return 0;
}

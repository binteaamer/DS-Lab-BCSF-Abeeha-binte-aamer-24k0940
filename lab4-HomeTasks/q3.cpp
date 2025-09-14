/*Implement the Selection Sort algorithm. The program should take an array of integers from
the user, find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user.*/

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

cout<<"un sorted array: "<<endl;
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<endl;

 for(int i=0;i<n-1;i++){
  int minIndex = i;
 for(int j=i+1;j<n;j++){
    if(arr[j]<arr[minIndex])
      minIndex = j;}
    if(minIndex != i){
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;}
    }
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
      cout<<endl;

    return 0;
}

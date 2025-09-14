/*Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array.*/
//code
#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter number of elements: ";
cin>>n;
  int arr[100];     
  cout<<"Enter "<<n<<" integers: ";
  for(int i=0;i<n;i++)
        cin>>arr[i];
  int target;
cout<<"Enter value to search: ";
cin>>target;
  int foundIndex = -1;
   
for(int i=0;i<n;i++){
  if(arr[i]==target){
    foundIndex = i;
    break;}
}
 if(foundIndex != -1)
    cout<<"element found at index: "<<foundIndex<<endl;
 else
   cout<<"Element not found in the array."<<endl;
    return 0;
}

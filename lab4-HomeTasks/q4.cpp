/*Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
Binary Search algorithm to find a target value within the newly sorted array. The program
should display the sorted array and the index of the found element or a message if it's not
present.*/

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
for(int i=1;i<n;i++){
  int key = arr[i];
  int j = i-1;
while(j>=0 && arr[j]>key){
  arr[j+1] = arr[j];
   j--;}
 arr[j+1] = key; }

cout<<"Sorted array: "<<endl;
 for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<endl;

int target;
cout<<"enter value to search: "<<endl;
cin>>target;

int low=0, high=n-1, foundIndex=-1;
while(low<=high){
  int mid = (low+high)/2;
  if(arr[mid]==target){
    foundIndex = mid;
    break; }
 else if(arr[mid]<target)
  low = mid+1;
 else high = mid-1;  }
  
if(foundIndex != -1)
cout<<"element found at index: "<<foundIndex<<endl;
  else
  cout<<"element not found in the array."<<endl;
    return 0;
}

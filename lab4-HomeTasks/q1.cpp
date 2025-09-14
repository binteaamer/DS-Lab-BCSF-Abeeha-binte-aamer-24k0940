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

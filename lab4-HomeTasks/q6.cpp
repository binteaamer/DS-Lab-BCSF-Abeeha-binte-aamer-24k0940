/*Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
decreases over time. After sorting, perform a complexity analysis: count and display the
total number of swaps and comparisons performed during the sorting process.*/

//code
#include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"eenter number of elements: "<<endl;
    cin>>n;
  int arr[100];
  cout<<"Enter "<<n<<" integers: "<<endl;
   for(int i=0;i<n;i++)
      cin>>arr[i];
int gap = n;
bool swapped = true;
int comparisons = 0, swaps = 0;

while(gap != 1 || swapped){
  gap = (gap * 10) / 13;
  if(gap < 1)
  gap = 1;
swapped = false;
for(int i=0; i+gap<n; i++){
 comparisons++;
 if(arr[i] > arr[i+gap]){
  int temp = arr[i];
  arr[i] = arr[i+gap];
  arr[i+gap] = temp;
  swaps++;
  swapped = true;  }
  }
 }
 cout<<"Sorted array: "<<endl;
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
 cout<<"Total comparisons: "<<comparisons<<endl;
 cout<<"Total swaps: "<<swaps<<endl;

    return 0;
}

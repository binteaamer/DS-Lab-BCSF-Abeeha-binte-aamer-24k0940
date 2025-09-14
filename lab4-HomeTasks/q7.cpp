/*Implement the Shell Sort algorithm to sort an array of integers. The algorithm should start
with a large gap, then perform a gapped insertion sort, and gradually reduce the gap until
it's 1. After sorting, compare its performance against the Bubble Sort and Insertion Sort
algorithms for the same input array size (e.g., 1000 elements). Record and display the time
taken and the number of comparisons/swaps for all three algorithms to demonstrate why
Shell Sort is an improvement over Insertion Sort.*/

//code
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &swaps, double &timeTaken) {
  clock_t start = clock();
  for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
   comparisons++;
   if(arr[j]>arr[j+1]){
 int temp=arr[j];
 arr[j]=arr[j+1];
 arr[j+1]=temp;
swaps++; } }
}
timeTaken = (double)(clock()-start)/CLOCKS_PER_SEC;
}

void insertionSort(int arr[], int n, int &comparisons, int &swaps, double &timeTaken) {
 clock_t start = clock();
  for(int i=1;i<n;i++){
    int key=arr[i];
    int j=i-1;
while(j>=0 && (++comparisons && arr[j]>key)){
  arr[j+1]=arr[j];
  swaps++;
 j--;}
arr[j+1]=key; }
timeTaken = (double)(clock()-start)/CLOCKS_PER_SEC; }

void shellSort(int arr[], int n, int &comparisons, int &swaps, double &timeTaken) {
 clock_t start = clock();
 for(int gap=n/2;gap>0;gap/=2){
 for(int i=gap;i<n;i++){
  int temp=arr[i];
  int j=i;
while(j>=gap && (++comparisons && arr[j-gap]>temp)){
   arr[j]=arr[j-gap];
   swaps++;
 j-=gap; }
arr[j]=temp;}}
timeTaken = (double)(clock()-start)/CLOCKS_PER_SEC;
}

int main(){
int n=1000;
int data[1000];
  srand(time(0));
for(int i=0;i<n;i++) data[i]=rand()%10000;
  int arr1[1000],arr2[1000],arr3[1000];
for(int i=0;i<n;i++){ arr1[i]=data[i]; arr2[i]=data[i]; arr3[i]=data[i]; }

int compB=0,swapB=0,compI=0,swapI=0,compS=0,swapS=0;
double timeB=0,timeI=0,timeS=0;

bubbleSort(arr1,n,compB,swapB,timeB);
insertionSort(arr2,n,compI,swapI,timeI);
shellSort(arr3,n,compS,swapS,timeS);

cout<<"Bubble Sort:"<<endl;
cout<<"Comparisons: "<<compB<<endl;
cout<<"swaps: "<<swapB<<endl;
cout<<"Time: "<<timeB<<" sec"<<endl<<endl;

cout<<"insertion Sort:"<<endl;
cout<<"comparisons: "<<compI<<endl;
cout<<"Swaps: "<<swapI<<endl;
cout<<"Time: "<<timeI<<" sec"<<endl<<endl;

cout<<"shell Sort:"<<endl;
cout<<"Comparisons: "<<compS<<endl;
cout<<"Swaps: "<<swapS<<endl;
cout<<"Time: "<<timeS<<" sec"<<endl;

return 0;}

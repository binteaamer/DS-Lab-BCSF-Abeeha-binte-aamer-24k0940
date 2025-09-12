#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
    if (arr[j] < arr[j + 1]) {
      int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;}
}}
}

int main(){
    int arr[10]={};
    
cout<<"input 10 elements for integer array to sort"<<endl;
for(int i=0;i<10;i++){
    cin>>arr[i];
}
cout<<"unsorted"<<endl;
for(int i=0;i<10;i++){
    cout<<arr[i];
}
cout<<" "<<endl;

bubblesort(arr,10);
cout<<"sorted"<<endl;
for(int i=0;i<10;i++){
    cout<<arr[i];
}
return 0;
}

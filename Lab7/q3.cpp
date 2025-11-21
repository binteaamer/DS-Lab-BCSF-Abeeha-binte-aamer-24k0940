//task 6 
//code
radix 
#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int mx = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[20];
    int count[10];
    for(int i=0;i<10;i++) count[i] = 0;

    for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;

    for(int i=1;i<10;i++) count[i] += count[i-1];

    for(int i=n-1;i>=0;i--){
        int idx = (arr[i]/exp)%10;
        output[count[idx]-1] = arr[i];
        count[idx]--;
    }

    for(int i=0;i<n;i++) arr[i] = output[i];
}

void radixSort(int arr[], int n){
    int mx = getMax(arr, n);
    for(int exp=1; mx/exp>0; exp*=10)
        countSort(arr, n, exp);
}

int main(){
    int arr1[10] = {10,3,15,7,8,23,74,18,2,9};
    int arr2[10] = {45,22,11,99,1,6,28,14,62,30};

    int arr[20];
    for(int i=0;i<10;i++) arr[i] = arr1[i];
    for(int i=0;i<10;i++) arr[i+10] = arr2[i];

    radixSort(arr, 20);

    for(int i=0;i<20;i++) cout<<arr[i]<<" ";
}


//merge 
#include <iostream>
using namespace std;

void mergeArrays(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[20], R[20];

    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int i=0;i<n2;i++) R[i] = arr[m+1+i];

    int i=0, j=0, k=l;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        mergeArrays(arr, l, m, r);
    }
}

int main(){
    int arr1[10] = {10,3,15,7,8,23,74,18,2,9};
    int arr2[10] = {45,22,11,99,1,6,28,14,62,30};

    int arr[20];
    for(int i=0;i<10;i++) arr[i] = arr1[i];
    for(int i=0;i<10;i++) arr[i+10] = arr2[i];

    mergeSort(arr, 0, 19);

    for(int i=0;i<20;i++) cout<<arr[i]<<" ";
}

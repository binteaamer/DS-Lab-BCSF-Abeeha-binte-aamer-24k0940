/*Task #2:
Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
=> Rows represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form.*/

//code
#include<iostream>
using namespace std;
int main () {
int benches,seats;
cout<<"enter benches and seats"<<endl;
cin>> benches >> seats;

int**arr =new int*[benches];
for(int i=0; i<benches; i++){
  arr[i]= new int[seats]{};
}
cout<<"enter status of each seat , 0 for no,1 for yes"<<endl;

for (int i=0;i < benches; i++){
    for(int j=0; j<seats;j++){
        cout<<"is seat "<<j<<" of row "<<i<<" free? "<<endl; 
        cin>>arr[i][j];
    }
}
cout<<"the seating chart"<<endl;
for (int i=0;i < benches; i++){
    for(int j=0; j<seats;j++){
        cout<<arr[i][j]<<" ";
        
    }
    cout<<endl;
}


for (int i=0;i < benches; i++){
    delete[] arr[i];}
    delete[] arr;
    
return 0;

}

/*Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly.
*/

//code:
#include<iostream>
using namespace std;
int main () {
int size;
cout<<"enter size! "<<endl;
cin>> size;

int* arr = new int[size] {};
int i;
while(true){
    cout<<"enter the position"<<endl;
    cin>>i;
    if(i>size| i < 0 ){cout<<"out of bound"<<endl;
        continue;
    }
    cout<<"enter the value"<<endl;
    cin>>arr[i];
    char a;
    cout<<"do you want to enter another value, enter y(yes), n(no)"<<endl;
    cin>>a;
    if (a=='n' || a=='N'){
        break;

    }

}

cout<<"array made"<<endl;
for(int i=0; i<size;i++){
    cout<<arr[i]<<endl;
}
delete[]arr;
return 0;

}

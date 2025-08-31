
/*Task #9:
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value).*/

//code
//commments are for my understanding 
#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows"<<endl;
    cin>>r;
    cout<<"enter number of coloumns"<<endl;
    cin>>c;
    
    int**matrix=new int*[r];
    for(int i=0;i<r;i++){
      matrix[i] = new int[c];
    }

    cout<<"enter matrix elements "<<r*c<<" values"<<endl;
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>matrix[i][j];

    }
}
cout << "normal form:"<<endl; 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

// main part, compressed matrix which is in form (row, col, value)and no zero
cout<<"the matrix in compressed form (row, column, value): "<<endl;
for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
    if (matrix[i][j] != 0) {
    cout << i << " " << j << " " << matrix[i][j] << endl; }
        }
    }

    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

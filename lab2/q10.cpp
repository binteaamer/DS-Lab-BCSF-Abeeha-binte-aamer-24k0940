/*Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category. */
//code
#include <iostream>
using namespace std;

int main() {
    int categories;
    cout<<"enter number of categories"<<endl;
    cin>>categories;

    int*size= new int [categories];
    int**books= new int*[categories];
    for (int i=0;i<categories;i++){
       cout << "Enter number of books in category " << i+1 << ": ";
       cin >> size[i];
      
       books[i]= new int[size[i]];
    
       cout<<"enter book IDS for category"<<i+1<<": "<<endl;
       for(int j=0;j<size[i];j++){
        cin>>books[i][j];}

       }
 int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;
      bool found = false;
    for (int i = 0; i < categories; i++) {
    for (int j = 0; j < size[i]; j++) {
      if (books[i][j] == searchID) {
        cout << "Book found in category " << i+1 << endl;
        found = true;
        break; }
        }
        if (found) break;
    if (!found) cout << "Book not available in library.\n";

    // free memory
    for (int i = 0; i < cat; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] size;

    return 0;

}

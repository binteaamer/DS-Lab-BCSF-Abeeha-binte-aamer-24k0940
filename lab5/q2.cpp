/*Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly.
*/
//code 
#include <iostream>
using namespace std; 

void printnumber(int n){
    if(n<1){
    return;}
    else{ cout<<n<<endl;
    printnumber(n-1); }
}

int main() {
int n;
cout<<"enter the number to print"<<endl;
cin>>n;
printnumber(n);
    return 0;
}


/*2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
and functionB(int n). functionA should call functionB, and functionB
should call functionA, forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops*/

//code
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n <= 0) return;
    cout << n << " ";
    functionB(n - 1);
}

void functionB(int n) {
    if (n <= 0) return;
    cout << n << " ";
    functionA(n - 1);
}

int main() {
    int n;
    cin >> n;
    functionA(n);
    cout << endl;
    return 0;
}


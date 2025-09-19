/*1. Implement a C++ function sumTail(int n, int total) that calculates the sum
of numbers from 1 to n using tail recursion. The recursive call should be the last
operation in the function.
*/
//code 
#include <iostream>
using namespace std;

int sumtail(int n, int total) {
    if (n <= 0) return total;
    return sumtail(n - 1, total + n);
}

int main() {
    int n;
    cin >> n;
    cout << sumtail(n, 0) << endl;
    return 0;
}

/*2. Implement another function sumNonTail(int n) that calculates the same sum
using non-tail recursion. This function should perform an operation (e.g., addition) after
the recursive call returns. Compare the two implementations and explain the difference
in their call stacks*/
//code 
#include <iostream>
using namespace std;

int sumnontail(int n) {
    if (n <= 0) return 0;
    return n + sumnontail(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << sumnontail(n) << endl;
    return 0;
}

Q1
/*Q1. Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named
account1. Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
an initial balance of $1000. Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new
BankAccount object named account3 using the copy constructor. Deduct $200 from
account3 and print out its balance. Also, print out the balance of account2 to ensure it
hasn't been affected by the transaction involving account3.
*/

code: 

#include <iostream>
using namespace std;

//default constructor 
class bankAccount {
private: 
double bal;
public:
//default constructor
bankAccount(){
bal=0;
}

//parametrized constructor 
bankAccount(double b){
bal=b;
}
//copy constructor 
bankAccount(const bankAccount &copy){
bal=copy.bal;
}

//functions to show deduction and balance in an account 

void deduct(double amount){
bal-= amount;
}

void balance(){
cout<<"Balance in account "<< bal<<" $"<<endl;
}
};

int main(){
bankAccount account1;
account1.balance();

bankAccount account2(1000);
account2.balance();

bankAccount account3(account2);
account3.deduct(500);
account3.balance();
account2.balance();

return 0;
}

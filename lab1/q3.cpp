/*Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/

code:

#inlcude<iostream>
using namespace std;

class box{

private: 
int *lenght;

public:
//constructr
box(int l){
  lenght =new int(l);
}

//destructor
~box(){
  delete lenght;
}

//copy constructor 
box(const box &copy){
  lenght = new int(*copy.lenght);
}
//copy assignment operator 
box& operator=(const box& copy){
if(this !=&copy){
  delete lenght;
  size=new int (*copy.size);
}
  return *this;
}
void show(){
  cout << "lenght of a side: "<<*lenght<<endl;
}
};

int main (){
  box b1(5);
  box b2=b1; 
  box b3(10);
  b3=b1;

  b1.show();
  b2.show();
  b3.show();
//all 3 will show 10 
  return 0;
  

}




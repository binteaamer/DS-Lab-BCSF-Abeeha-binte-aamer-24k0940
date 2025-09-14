/*1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise.*/

//code
#include<iostream>
using namespace std;

class node{
  public:
node* next;
int data; 
node(int val){
    data = val;
    next = NULL;
  }
};
class linkedList{
node* head;
public:
linkedList(){
    head = NULL;
  }

void addnodes(int val){
node* n = new node(val);
if(!head){
head = n;
return;}
node* t = head;
  while(t->next)
      t = t->next;
    t->next = n;}
bool checkPalindrome(){
if(!head || !head->next) return true;
    node* midPtr = head;
    node* jumpPtr = head;
while(jumpPtr && jumpPtr->next){
 midPtr = midPtr->next;
jumpPtr = jumpPtr->next->next;}
  node* prev = NULL;
  node* curr = midPtr;
  node* nxt = NULL;
  
while(curr){
nxt = curr->next;
curr->next = prev;
prev = curr;
 curr = nxt;}
node* first = head;
node* second = prev;

while(second){
if(first->data != second->data) return false;
 first = first->next;
      second = second->next;}
 return true;
}
void show(){
node* t = head;
while(t){
  cout<<t->data<<" ";
      t = t->next;
    }
    cout<<endl;
  }
};

int main(){
  linkedList l;
  l.addnodes(1);
  l.addnodes(2);
  l.addnodes(3);
  l.addnodes(2);
  l.addnodes(1);

  l.show();

if(l.checkPalindrome()) cout<<"true";
else cout<<"false";
}

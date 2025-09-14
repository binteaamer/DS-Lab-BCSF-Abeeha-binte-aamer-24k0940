/*Flatten a Multilevel Linked List
Each node has:
• next pointer (normal linked list connection).

Lab Manual 03
• child pointer (points to another linked list).
Write a function to flatten the structure so that all nodes appear in a single-level list.
• Example:
• 1 → 2 → 3
• |
• 4 → 5
Output: 1 → 2 → 4 → 5 → 3*/

//code

#include<iostream>
using namespace std;
class Node{
   public:
   int data;
   Node* next;
   Node* child;

   Node(int val){
      data=val;
      next=NULL;
      child=NULL;}
};

class LinkedList{
   Node* head;
   public:
   LinkedList(){
      head=NULL; }

  void addNode(int val){
       Node* n=new Node(val);
    if(!head){ head=n; return; }
      Node* t=head;
       while(t->next) t=t->next;
       t->next=n;}

Node* getHead(){ return head; }
 void setChild(Node* parent, Node* childHead){
  parent->child=childHead;}

void flatten(){
 Node* curr=head;
  while(curr){
 if(curr->child){
 Node* tempNext = curr->next;
  curr->next = curr->child;
  Node* tail=curr->child;
 while(tail->next)
   tail=tail->next;
   tail->next = tempNext;
    curr->child=NULL;}
    curr=curr->next; }
}
void display(){
  Node* t=head;
  while(t){
    cout<<t->data<<" ";
    t=t->next;}
    cout<<endl;}
};
int main(){
LinkedList mainList;
  mainList.addNode(1);
  mainList.addNode(2);
  mainList.addNode(3);
  
  LinkedList childList;
  childList.addNode(4);
  childList.addNode(5);
  mainList.setChild(mainList.getHead()->next, childList.getHead());

  cout<<"Before Flatten: "<<endl;
      mainList.display();
      mainList.flatten();

  cout<<"\nAfter Flatten: "<<endl;
  mainList.display();
  return 0;}

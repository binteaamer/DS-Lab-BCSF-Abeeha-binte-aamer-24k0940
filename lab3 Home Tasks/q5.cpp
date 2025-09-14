/*Implement functions for conversion:
1. Convert a singly linked list into a doubly linked list.
2. Convert a singly linked list into a circular linked list.
• Demonstrate both conversions with sample input lists.*/

//code

#include<iostream>
using namespace std;
class Snode{
 public:
 int data;
 Snode* next;
 Snode(int v){ data=v; next=NULL; }
};

class Dnode{
 public:
 int data;
 Dnode* next;
 Dnode* prev;
 Dnode(int v){ data=v; next=NULL; prev=NULL; }
};
class SinglyList{
 Snode* head;
 public:
 SinglyList(){ head=NULL; }

void add(int v){
Snode* n=new Snode(v);
if(!head){ head=n; return; }
  Snode* t=head;
while(t->next) t=t->next;
t->next=n;}

void show(){
  Snode* t=head;
while(t){ cout<<t->data<<" "; t=t->next; }
  cout<<endl;
 }
Snode* getHead(){ return head; }

 //Convert Singly to Doubly
 Dnode* toDoubly(){
  if(!head) return NULL;
  Snode* t=head;
  Dnode* dHead=NULL; Dnode* dPrev=NULL;

  while(t){
   Dnode* dn=new Dnode(t->data);
   if(!dHead) dHead=dn;
   dn->prev=dPrev;
   if(dPrev) dPrev->next=dn;
   dPrev=dn;
   t=t->next;
  }
  return dHead;
 }

 //convert Singly to Circular 
 Snode* toCircular(){
  if(!head) return NULL;
  Snode* t=head;
  while(t->next) t=t->next;
  t->next=head; // make circular
  return head;
 }
};

//show doubly
void showD(Dnode* h){
 while(h){
  cout<<h->data<<" ";
  h=h->next;
 }
 cout<<endl;
}

//show circular
void showC(Snode* h,int n){
 Snode* t=h;
 for(int i=0;i<n;i++){
  cout<<t->data<<" ";
  t=t->next;
 }
 cout<<endl;}

int main(){
 SinglyList L;
 L.add(10); L.add(20); L.add(30); L.add(40);

 cout<<"Singly: ";
 L.show();
 // convert in doubly
 Dnode* d = L.toDoubly();
 cout<<"Doubly: ";
 showD(d);

 // convertin circular
 Snode* c = L.toCircular();
 cout<<"Circular: ";
 showC(c,8); 
}

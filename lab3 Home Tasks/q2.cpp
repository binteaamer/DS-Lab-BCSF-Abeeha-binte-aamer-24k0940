/*2. Merge Two Sorted Singly Linked Lists
Implement a function to merge two sorted singly linked lists into one sorted list.

Lab Manual 03

• Example:
o List A: 1 → 3 → 5
o List B: 2 → 4 → 6
o Output: 1 → 2 → 3 → 4 → 5 → 6
• Bonus: Solve without creating new nodes (rearrange pointers).*/

//code

#include<iostream>
using namespace std;

class node{
 public:
 int data;
 node* next;
  node(int v){
   data=v; next=NULL;
 }};

class linkedList{
  public:
 node* head;

 linkedList(){ head=NULL; }

 void addnodes(int val){
 node* n=new node(val);
 if(!head){ head=n; return; }
 node* t=head;
 while(t->next) t=t->next;
 t->next=n;}

 void show(){
  node* x=head;
  while(x){
 cout<<x->data<<" ";
   x=x->next;
    }
cout<<endl;
 }
 static node* mergeSorted(node* h1,node* h2){
    if(!h1) return h2;
     if(!h2) return h1;

  node* res=NULL; node* tail=NULL;

 if(h1->data< h2->data)
 { res=h1; h1=h1->next; }
 else{ res=h2; h2=h2->next; }

 tail=res;

  while(h1 && h2){
   if(h1->data<h2->data){
    tail->next=h1; h1=h1->next;
   }
   else{
  tail->next=h2; h2=h2->next;
   }
  tail=tail->next;
  }

 if(h1) tail->next=h1;
  else tail->next=h2;

 return res;
 }

};

int main(){
 linkedList A,B;

 A.addnodes(1);
A.addnodes(3);
 A.addnodes(5);

 B.addnodes(2);
  B.addnodes(4);
 B.addnodes(6);

 cout<<"List A: ";
A.show();
cout<<"List B: ";
B.show();

 node* merged=linkedList::mergeSorted(A.head,B.head);

 cout<<"Merged: ";
 node* p=merged;
 while(p){
 cout<<p->data<<" ";
  p=p->next;}}

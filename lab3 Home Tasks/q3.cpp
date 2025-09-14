/*Reverse nodes of a singly linked list in groups of size k.
• Example:
o Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k =*/

//code

#include<iostream>
using namespace std;

class node{
 public:
 int data;
 node* next;
 node(int v){ data=v; next=NULL; }
};

class linkedList{
 node* head;
 public:

 linkedList(){ head=NULL; }

 void addnodes(int v){
  node* n=new node(v);
  if(!head){ head=n; return; }
  node* t=head;
  while(t->next) t=t->next;
  t->next=n;
 }

 void show(){
  node* t=head;
  while(t){ cout<<t->data<<" "; t=t->next; }
  cout<<endl;
 }

 node* getHead(){ return head; }
 void setHead(node* h){ head=h; }

 static node* reverseInGroups(node* start,int k){
  if(!start) return NULL;
   node* curr=start;
    node* prev=NULL;
     node* nxt=NULL;
      int count=0;

  while(curr && count<k){
   nxt=curr->next;
   curr->next=prev;
   prev=curr;
   curr=nxt;
   count++;
  }

 if(nxt)
  start->next=reverseInGroups(nxt,k);

 return prev;
 }
};

int main(){
 linkedList L;
 L.addnodes(1);
 L.addnodes(2);
 L.addnodes(3);
 L.addnodes(4);
 L.addnodes(5);
 L.addnodes(6);
 L.addnodes(7);
 L.addnodes(8);

 cout<<"Before: ";
 L.show();

 node* newHead = linkedList::reverseInGroups(L.getHead(),3);
 L.setHead(newHead);

 cout<<"After: ";
 L.show();
}

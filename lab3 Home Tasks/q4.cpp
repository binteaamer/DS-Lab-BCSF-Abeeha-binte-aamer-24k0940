/*Use a circular linked list to solve the Josephus problem:
• N people stand in a circle, eliminating every k-th person until only one survives.
• Input: N = 7, k = 3
• Output: Position of survivor.
• Hint: Use circular traversal and deletion.*/
//code

#include<iostream>
using namespace std;

class node{
 public:
 int data;
 node* next;
 node(int v){ data=v; next=NULL; }
};

class circularList{
 node* head;

 public:
 circularList(){ head=NULL; }

 void create(int n){
   if(n<=0) return;
   node* prev=NULL;
   for(int i=1;i<=n;i++){
     node* x=new node(i);
     if(!head) head=x;
     else prev->next=x;
     prev=x;}
   prev->next=head; }

 int josephus(int k){
   if(!head || head->next==head) return head->data;

   node* curr=head;
   node* prev=NULL;

   while(curr->next!=curr){
     for(int count=1; count<k; count++){
       prev=curr;
       curr=curr->next;}

     prev->next=curr->next;
     node* temp=curr;
     curr=curr->next;
     delete temp;
   }
   head=curr;
   return curr->data;
 }
};

int main(){
 circularList circle;
 circle.create(7);
 int survivor = circle.josephus(3);
 cout<<"Survivoor at position: "<<survivor;
}

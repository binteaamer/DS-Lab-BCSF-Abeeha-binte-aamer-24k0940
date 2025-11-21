//code
//task5 

#include <iostream>
using namespace std;

struct Node{
int data;
Node* next;
Node(int d){data=d;next=NULL;}
};

void push(Node*& head,int d){
Node* n=new Node(d);
n->next=head;
head=n;
}

void swapNodes(Node* a,Node* b){
int t=a->data;
a->data=b->data;
b->data=t;
}

Node* partition(Node* head,Node* end,Node*& newHead,Node*& newEnd){
Node* pivot=end;
Node* prev=NULL;
Node* curr=head;
Node* tail=pivot;
while(curr!=pivot){
if(curr->data<pivot->data){
if(newHead==NULL)newHead=curr;
prev=curr;
curr=curr->next;
}
else{
if(prev)prev->next=curr->next;
Node* tmp=curr->next;
curr->next=NULL;
tail->next=curr;
tail=curr;
curr=tmp;
}
}
if(newHead==NULL)newHead=pivot;
newEnd=tail;
return pivot;
}

Node* quickSortRec(Node* head,Node* end){
if(!head||head==end)return head;
Node* newHead=NULL;
Node* newEnd=NULL;
Node* pivot=partition(head,end,newHead,newEnd);
if(newHead!=pivot){
Node* tmp=newHead;
while(tmp->next!=pivot)tmp=tmp->next;
tmp->next=NULL;
newHead=quickSortRec(newHead,tmp);
tmp=newHead;
while(tmp->next)tmp=tmp->next;
tmp->next=pivot;
}
pivot->next=quickSortRec(pivot->next,newEnd);
return newHead;
}

void quickSort(Node*& head){
Node* end=head;
if(!head)return;
while(end->next)end=end->next;
head=quickSortRec(head,end);
}

void printList(Node* head){
while(head){
cout<<head->data<<" ";
head=head->next;
}
}

int main(){
Node* head=NULL;
push(head,3);
push(head,5);
push(head,1);
push(head,9);
push(head,8);
push(head,7);
push(head,10);
quickSort(head);
printList(head);
}

/* Task 7 – Application of Stack & Queue (Advanced)
   Design a job scheduling system where:
   1. Processes (with IDs & priorities) arrive and are stored in a queue.
   2. Execution order is determined using a stack (LIFO execution of high-priority tasks).
   3. Demonstrate how both queue (arrival order) and stack (execution handling) are combined.
*/
//code
//abeeha binte aamer 24k0940
#include <iostream>
using namespace std;

class Process{
public:int id,priority;
};

class Queue{
    Process q[50];int f,r;
public:
    Queue(){f=r=-1;}
    bool empty(){return f==-1;}
    void enqueue(Process p){
        if(r==49)return;
        if(f==-1)f=0;
        q[++r]=p;
    }
    Process dequeue(){
        Process p=q[f];
        if(f==r)f=r=-1;else f++;
        return p;
    }
};

class Stack{
    Process s[50];int t;
public:
    Stack(){t=-1;}
    void push(Process p){s[++t]=p;}
    Process pop(){return s[t--];}
    bool empty(){return t==-1;}
};

int main(){
    Queue q;Stack st;int n;
    cout<<"Enter number of processes: ";cin>>n;
    for(int i=0;i<n;i++){
        Process p;
        cout<<"ID: ";cin>>p.id;
        cout<<"Priority: ";cin>>p.priority;
        q.enqueue(p);
    }
    cout<<"\nArrival Order (Queue):\n";
    Queue temp=q;
    while(!temp.empty()){
        Process p=temp.dequeue();
        cout<<"Process "<<p.id<<" Priority "<<p.priority<<endl;
        if(p.priority>5)st.push(p);
    }
    cout<<"\nExecution Order (Stack - LIFO for high priority):\n";
    while(!st.empty()){
        Process p=st.pop();
        cout<<"Executing Process "<<p.id<<" Priority "<<p.priority<<endl;
    }
}

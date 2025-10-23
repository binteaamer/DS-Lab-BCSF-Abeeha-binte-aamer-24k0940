/* Task 5 – Infix to Postfix Conversion using Stack
   Write a program to convert an infix expression into postfix form using a stack.
   Also, evaluate the postfix expression afterward.
*/
//code
//abeeha binte aamer 24k0940
#include <iostream>
using namespace std;

class Stack {
    char a[100]; int t;
public:
    Stack(){t=-1;}
    void push(char c){a[++t]=c;}
    char pop(){return a[t--];}
    char top(){return a[t];}
    bool empty(){return t==-1;}
};

int prec(char c){
    if(c=='^')return 3;
    if(c=='*'||c=='/')return 2;
    if(c=='+'||c=='-')return 1;
    return 0;
}

int power(int b,int e){int p=1;for(int i=0;i<e;i++)p*=b;return p;}

void infixToPostfix(char in[],char post[]){
    Stack s;int j=0;
    for(int i=0;in[i]!='\0';i++){
        char c=in[i];
        if(c==' ')continue;
        if(c>='0'&&c<='9')post[j++]=c;
        else if(c=='(')s.push(c);
        else if(c==')'){while(!s.empty()&&s.top()!='(')post[j++]=s.pop();s.pop();}
        else{
            while(!s.empty()&&prec(s.top())>=prec(c))post[j++]=s.pop();
            s.push(c);
        }
    }
    while(!s.empty())post[j++]=s.pop();
    post[j]='\0';
}

int evalPostfix(char post[]){
    int st[100],t=-1;
    for(int i=0;post[i]!='\0';i++){
        char c=post[i];
        if(c>='0'&&c<='9')st[++t]=c-'0';
        else{
            int b=st[t--],a=st[t--];
            if(c=='+')st[++t]=a+b;
            else if(c=='-')st[++t]=a-b;
            else if(c=='*')st[++t]=a*b;
            else if(c=='/')st[++t]=a/b;
            else if(c=='^')st[++t]=power(a,b);
        }
    }
    return st[t];
}

int main(){
    char in[100],post[100];
    cout<<"Enter infix: ";
    cin.getline(in,100);
    infixToPostfix(in,post);
    cout<<"Postfix: "<<post<<endl;
    cout<<"Value: "<<evalPostfix(post)<<endl;
}

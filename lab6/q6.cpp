/* Task 6 – Infix to Prefix Conversion using Stack
   Write a program to convert an infix expression into prefix form using stack rules.
   Include operator precedence and associativity handling.
   Evaluate the prefix expression as well.
*/
//code
//abeeha binte aamer 24k0940
#include <iostream>
using namespace std;

class Stack {
    char a[100];int t;
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

void rev(char s[]){
    int n=0;while(s[n]!='\0')n++;
    for(int i=0;i<n/2;i++){char t=s[i];s[i]=s[n-1-i];s[n-1-i]=t;}
}

void infixToPrefix(char in[],char pre[]){
    Stack s;rev(in);int j=0;
    for(int i=0;in[i]!='\0';i++){
        char c=in[i];
        if(c==' ')continue;
        if(c>='0'&&c<='9')pre[j++]=c;
        else if(c==')')s.push(c);
        else if(c=='('){while(!s.empty()&&s.top()!=')')pre[j++]=s.pop();s.pop();}
        else{
            while(!s.empty()&&prec(s.top())>prec(c))pre[j++]=s.pop();
            s.push(c);
        }
    }
    while(!s.empty())pre[j++]=s.pop();
    pre[j]='\0';
    rev(pre);
}

int evalPrefix(char pre[]){
    int st[100],t=-1;
    int n=0;while(pre[n]!='\0')n++;
    for(int i=n-1;i>=0;i--){
        char c=pre[i];
        if(c>='0'&&c<='9')st[++t]=c-'0';
        else{
            int a=st[t--],b=st[t--];
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
    char in[100],pre[100];
    cout<<"Enter infix: ";
    cin.getline(in,100);
    infixToPrefix(in,pre);
    cout<<"Prefix: "<<pre<<endl;
    cout<<"Value: "<<evalPrefix(pre)<<endl;
}

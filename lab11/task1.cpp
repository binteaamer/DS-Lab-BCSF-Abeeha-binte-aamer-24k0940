//question 
//code 
#include<iostream>
//#define buckets 10 
using namespace std; 
struct node{
    string key;
    string value;
    node* next;
};

class hashtable{
    public:
    static const int buckets=10; 
    node*table[buckets];

    int hashfunction(const string& key){
    int sum=0;
    for(char c : key){
        sum+=c;}
    return sum%buckets;}

hashtable(){
    for (int i=0;i<buckets;i++){
        table[i]=nullptr;   }
}
void insert(const string&key, const string&value){
    int index= hashfunction(key);
    node* newnode= new node{key, value, nullptr};
    if(table[index]==nullptr){
        table[index]=newnode;
    }else {node*temp= table[index];
    while(temp->next!=nullptr){
        if(temp->key==key){
            temp->value=value;
            delete newnode;
            return;
        }
        temp=temp->next;
    }
}

}
void display(){
    for (int i=0;i<buckets;i++){
        node*temp=table[i];
        if(!temp){cout<<"empty"<<endl;}
    while(temp){
    cout<<"key: "<<temp->key<<", value : "<<temp->value<<endl;
    temp=temp->next;}
    cout<<endl;
    }
}
     
};

int main(){
    hashtable h1;
    h1.insert("A", "aaaaa");
    h1.insert("B", "bbbbb");
    h1.insert("C", "ccccc");
    h1.insert("D", "ddddd");
    h1.display();
}

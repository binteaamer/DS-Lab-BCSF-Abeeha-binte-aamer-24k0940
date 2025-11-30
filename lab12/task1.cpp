// code for bfs 
#include<iostream>
using namespace std;

int main(){
 string t , p;
    cout<<"text: "; getline(cin,t);
 cout<<"pat: "; getline(cin,p);

 int n=t.size() , m=p.size() , cmp=0;

        cout<<"idx: [";
 bool f=0;
 for(int i=0;i<=n-m;i++){
            int j=0;
        while(j<m && t[i+j]==p[j]){
 cmp++; j++;
        }
        if(j<m) cmp++;
 if(j==m){
            if(f) cout<<", ";
            cout<<i; f=1;
 }
 }

 cout<<"]\n";
 cout<<"cmp: "<<cmp;
}

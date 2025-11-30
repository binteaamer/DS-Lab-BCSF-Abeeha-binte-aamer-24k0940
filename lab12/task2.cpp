//rbain karp 
#include<iostream>
using namespace std;

int main(){
 string t,p;
    cout<<"text: "; getline(cin,t);
 cout<<"pat: "; getline(cin,p);

 int n=t.size(), m=p.size();
 int d=256 , q=101;
 int h=1 , ph=0 , th=0;

 for(int i=0;i<m-1;i++) h=(h*d)%q;
 for(int i=0;i<m;i++){
  ph=(d*ph+p[i])%q;
  th=(d*th+t[i])%q;
 }

 cout<<"idx: [";
 bool f=0;

 for(int i=0;i<=n-m;i++){
  if(ph==th){ bool ok=1;
  for(int j=0;j<m;j++){
  if(t[i+j]!=p[j]) ok=0;}
  if(ok){
      if(f) cout<<", ";
      cout<<i; f=1;
      } else {
          cout<<"\nfalse collision at "<<i;}}
  if(i<n-m){
 th=(d*(th - t[i]*h) + t[i+m])%q;
 if(th<0) th+=q; }}

 cout<<"]";
}

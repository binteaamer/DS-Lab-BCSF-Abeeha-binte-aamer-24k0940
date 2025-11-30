//kmp with lps array used in this nne
//code

#include<iostream>
using namespace std;

int main(){
 string t,p;
 getline(cin,t);
 getline(cin,p);

 int n=t.size(), m=p.size();
 int *lps=new int[m];

 lps[0]=0;
 int len=0 , i=1;
 while(i<m){
    if(p[i]==p[len]){
        len++; lps[i]=len; i++;
    } else {
        if(len!=0) len=lps[len-1];
        else lps[i]=0, i++;}}
 cout<<"lps: ";
 for(int k=0;k<m;k++) cout<<lps[k]<<" ";
 cout<<"\nidx: [";

 bool f=0;
 i=0; int j=0;
 while(i<n){
 if(t[i]==p[j]){ i++; j++; }
   if(j==m){
   if(f) cout<<", ";
    cout<<i-j; f=1;
        j=lps[j-1];  
   } else if(i<n && t[i]!=p[j]){
     if(j!=0) j=lps[j-1];
     else i++;}}

 cout<<"]";

 delete[] lps;
}

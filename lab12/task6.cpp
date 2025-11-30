/*Edges:

B–A = 4

B–C = 9

A–D = 8

C–D = 6

C–E = 14

D–F = 4

F–E = 3

We find shortest B → E.*/
//code 
#include<iostream>
using namespace std;

int main(){
 const int n=6;
 int g[n+1][n+1];

 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   g[i][j]=0;

 auto w=[&](char c){ return c-'A'+1; };

 g[w('B')][w('A')]=4; g[w('A')][w('B')]=4;
 g[w('B')][w('C')]=9; g[w('C')][w('B')]=9;
 g[w('A')][w('D')]=8; g[w('D')][w('A')]=8;
 g[w('C')][w('D')]=6; g[w('D')][w('C')]=6;
 g[w('C')][w('E')]=14;g[w('E')][w('C')]=14;
 g[w('D')][w('F')]=4; g[w('F')][w('D')]=4;
 g[w('F')][w('E')]=3; g[w('E')][w('F')]=3;

 int src=w('B'), dst=w('E');
 int d[n+1], vis[n+1]={0}, par[n+1];
 for(int i=1;i<=n;i++) d[i]=1e9, par[i]=-1;
 d[src]=0;

for(int k=1;k<=n;k++){
int u=-1;
for(int i=1;i<=n;i++)
if(!vis[i] && (u==-1 || d[i]<d[u])) u=i;
vis[u]=1;

  for(int v=1;v<=n;v++)
     if(g[u][v] && d[u]+g[u][v]<d[v]){
        d[v]=d[u]+g[u][v];
        par[v]=u; }
}
 cout<<"dist B->E = "<<d[dst]<<"\npath: ";

 int path[10], sz=0;
 for(int x=dst;x!=-1;x=par[x]) path[sz++]=x;
 for(int i=sz-1;i>=0;i--)
   cout<<char(path[i]+'A'-1)<<" ";
}

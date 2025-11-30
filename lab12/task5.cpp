/*Edges:
1–4
1–2
2–5
2–4
3–5

Nodes: 1..5

*/

//code
#include<iostream>
using namespace std;

int main(){
 const int n=5;
 int g[n+1][n+1];

 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   g[i][j]=0;

 int e[][2]={{1,4},{1,2},{2,5},{2,4},{3,5}};
 for(int k=0;k<5;k++){
  int a=e[k][0], b=e[k][1];
  g[a][b]=g[b][a]=1;
 }

 cout<<"adj list:\n";
 for(int i=1;i<=n;i++){
  cout<<i<<": ";
  for(int j=1;j<=n;j++) if(g[i][j]) cout<<j<<" ";
  cout<<"\n";
 }

 cout<<"\nadj matrix:\n";
 for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++) cout<<g[i][j]<<" ";
  cout<<"\n";
 }

 cout<<"\nbfs: ";
 int q[10],f=0,r=0,vis1[n+1]={0};
 q[r++]=1; vis1[1]=1;
 while(f<r){
   int u=q[f++];
   cout<<u<<" ";
   for(int v=1;v<=n;v++)
     if(g[u][v] && !vis1[v]){
       vis1[v]=1;
       q[r++]=v;
     }
 }

 cout<<"\ndfs: ";
 int st[10],top=0,vis2[n+1]={0};
 st[top++]=1;
 while(top){
   int u=st[--top];
   if(!vis2[u]){
     vis2[u]=1;
     cout<<u<<" ";
     for(int v=n;v>=1;v--)
       if(g[u][v] && !vis2[v])
         st[top++]=v;}}
}

/*Create a program that solves the N Queens problem using backtracking*/
//code
#include<iostream>
using namespace std;

bool issafe(int board[10][10],int r,int c,int n){
   for(int i=0;i<r;i++)
      if(board[i][c]) return false;
   for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
      if(board[i][j]) return false;
   for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++)
      if(board[i][j]) return false;
   return true;
}

bool solve(int board[10][10],int r,int n){
  if(r==n){
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
     cout<<board[i][j]<<" ";
     cout<<"\n"; }
    cout<<"------\n";
      return true;
   }
   bool res=false;
   for(int c=0;c<n;c++){
      if(issafe(board,r,c,n)){
      board[r][c]=1;
      res=solve(board,r+1,n)||res;
      board[r][c]=0;
      }
   }
   return res;
}

int main(){
   int n;
   cout<<"enter n : ";
   cin>>n;
   int board[10][10]={0};
   if(!solve(board,0,n))
      cout<<"no solution";
}

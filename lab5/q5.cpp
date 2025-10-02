/*Implement a Sudoku solver using backtracking*/
//code
#include<iostream>
using namespace std;

bool issafe(int grid[9][9],int r,int c,int val){
for(int i=0;i<9;i++){
if(grid[r][i]==val || grid[i][c]==val) return false;}
int sr=r-r%3, sc=c-c%3;
for(int i=0;i<3;i++)
  for(int j=0;j<3;j++)
  if(grid[sr+i][sc+j]==val) return false;
  return true;}

bool solvesudoku(int grid[9][9]){
  for(int r=0;r<9;r++){
    for(int c=0;c<9;c++){
        if(grid[r][c]==0){
     for(int val=1;val<=9;val++){
       if(issafe(grid,r,c,val)){
        grid[r][c]=val;
      if(solvesudoku(grid)) return true;
       grid[r][c]=0;}  }
      return false; } }}
   return true;
}

int main(){
   int grid[9][9];
   cout<<"enter sudoku (0 for empty):\n";
   for(int i=0;i<9;i++)
     for(int j=0;j<9;j++)
       cin>>grid[i][j];
   if(solvesudoku(grid)){
    cout<<"solved sudoku:\n";
   for(int i=0;i<9;i++){
     for(int j=0;j<9;j++)
       cout<<grid[i][j]<<" ";
      cout<<"\n";}}
  else cout<<"no solution";
}

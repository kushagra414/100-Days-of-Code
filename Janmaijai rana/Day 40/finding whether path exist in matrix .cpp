#include <bits/stdc++.h>
using namespace std;

int solveit(int i,int j,int m[20][20],bool visited[20][20],int n) 
{
   if(i>=0 && i<n && j>=0 && j<n && m[i][j]!=0 && !visited[i][j]){
      visited[i][j]=true;
      if(m[i][j]==2)
        return 1;
        
    return solveit(i+1,j,m,visited,n) || solveit(i-1,j,m,visited,n) || solveit(i,j+1,m,visited,n) || solveit(i,j-1,m,visited,n) ;    
   }   
   return 0;
}

int result(int m[20][20],int n){
      bool visited[20][20];
      memset(visited,false,sizeof(visited));
      
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(m[i][j]==1)
              return solveit(i,j,m,visited,n);
          }
      }



}
int main() {
    int t=0;
    cin>>t;
    while(t){
	   int n=0;
	   cin>>n;
	  // std::array<int int,n>m
	   int m[20][20];
	   for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++)
	          cin>>m[i][j];
	   }
	cout<<result(m,n);
	cout<<endl;
	t--;
    }
	return 0;
}

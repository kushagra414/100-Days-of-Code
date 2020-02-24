#include <bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}


int main() {
   int t;
   cin>>t;
   while(t){
       int n,e;
       cin>>n>>e;
       stack<int> s;
       queue<int> q;
    vector<int> G[n];
    for(int i=0;i<e;i++){
        int v,u;
        cin>>u>>v;
        addedge(G,u,v);
    }
    
      vector<int> F[n];
    for(int i=0;i<e;i++){
        int v,u;
        cin>>u>>v;
        addedge(F,u,v);
    }

   
   
     for(int i=0;i<n;i++)
        reverse(F[i].begin(),F[i].end());
       int flag=1; 
     for(int i=0;i<n;i++) {
           if(G[i]!=F[i]){
             flag=0;
             break;}
     } 
     if(flag==0)
     cout<<0<<endl;
     else
     cout<<1<<endl;
     
       
       t--;
   }
	return 0;
}

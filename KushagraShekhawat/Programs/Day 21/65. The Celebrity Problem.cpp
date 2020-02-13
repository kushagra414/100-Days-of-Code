// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends
// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
        for(int i=0;i<n;){
        int foundStranger=1,foundCeleb=1;
        int j=i+1;
        for(;j<n;j++){
            if(M[i][j]==1){
                i=j;
                foundStranger=0;
                break;
            }
        }
        if(foundStranger){
            //Check if Stranger is Celeb
            for(int k=0;k<n;k++){
                if(M[k][i]==0&&k!=i){
                    foundCeleb=0;
                    break;
                }
            }
        }
        if(foundCeleb){
            //Check if Celebrity knows anyone
            for(int k=0;k<n;k++)
                if(M[i][k]==1&&i!=k){
                    foundCeleb=0;
                    break;
                }
            if(foundCeleb)
                return i;
            else
                foundCeleb=0;
        }
        i++;
    }
    return -1;
}

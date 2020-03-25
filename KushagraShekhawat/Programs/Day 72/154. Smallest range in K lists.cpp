// { Driver Code Starts
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define N 1000

void findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    findSmallestRange(arr, n, k);
    }   
	return 0;
}

// } Driver Code Ends
// you are required to complete this function 
// function should print the required range

struct Matrix{
    int ele;
    int row;
    int column;
    Matrix(int element, int rowInd, int columnInd){
        ele = element;
        row = rowInd;
        column = columnInd;
    }
};

struct CompareEleMin{
    bool operator()(Matrix const &ele1, Matrix const &ele2){
        return ele1.ele>ele2.ele;
    }
};

void findSmallestRange(int arr[][N], int n, int k)
{
    int max=INT_MIN,min=INT_MIN,flag=0;
    Matrix maximum = Matrix(0,0,0);
    Matrix minimum = Matrix(0,0,0);
    priority_queue<Matrix, vector<Matrix>, CompareEleMin>Minpq;
    for(int i=0;i<k;i++){
        if(max<arr[i][0]){
            max = arr[i][0];
            maximum = Matrix(arr[i][0],i,0);
        }
        Minpq.push(Matrix(arr[i][0],i,0));
    }
    minimum = Minpq.top();
    min = minimum.ele;
    Minpq.pop();
    for(int i=0;i<k and flag==0;i++)
        for(int j=1;j<n;j++)
        {
            int col = minimum.column+1;
            int row = minimum.row;
            if(row<k and col<n){
                Minpq.push(Matrix(arr[row][col],row,col));
                Matrix temp = Matrix(arr[row][col],row,col);
                maximum = temp.ele>maximum.ele?temp:maximum;
                minimum = Minpq.top();
                if(max-min>maximum.ele-minimum.ele){
                    max = maximum.ele;
                    min = minimum.ele;
                    if(max-min==0){
                        flag=1;
                        break;
                    }
                }
                Minpq.pop();
            }
            else{
                flag=1;
                break;
            }
    }
    cout<<min<<" "<<max<<endl;
}
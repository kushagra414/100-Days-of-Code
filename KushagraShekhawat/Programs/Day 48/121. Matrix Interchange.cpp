// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

int arr[1000][1000];

void interchange(int ,int );

 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++
//Complete this function
//The array arr is globally declared
void interchange(int r,int c)
{
    int col1 = 0,col2=c-1;
    for(int row=0;row<r;row++){
        int temp = arr[row][col1];
        arr[row][col1] = arr[row][col2];
        arr[row][col2] = temp;
    }
  
  //Printing the modified matrix
    for(int i=0;i<r;i++)
	   { 
	       for(int j=0;j<c;j++)
    	    {
    	        cout<<arr[i][j]<<" ";
    	        
    	    }
    	 cout<<endl;
	   }
}


// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int r,c;
	    cin>>r>>c;
	    for(int i=0;i<r;i++)
	    for(int j=0;j<c;j++)
	    cin>>arr[i][j];
	    
	    
	    interchange( r, c);
	}
	return 0;
}

  // } Driver Code Ends

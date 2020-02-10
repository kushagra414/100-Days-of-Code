//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Structure for Min Heap
struct MinHeap
{   
    int *harr; 
    int capacity;
    int heap_size;
    
    // Constructor for Min Heap
    MinHeap(int c) {     
       heap_size = 0;
       capacity = c;
       harr = new int[c];
    }
    
    ~MinHeap()
    {
        delete[] harr;
    }
    
    int parent(int i) 
    { 
        return (i-1)/2; 
    }
    
    int left(int i) 
    { 
        return (2*i + 1);
    }
    
    int right(int i) 
    { 
        return (2*i + 2);
    }
    
    void MinHeapify(int ); // Implemented in user editor
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
    
};



 // } Driver Code Ends

/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap=100) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};*/

// You need to write code for below three functions
    
/* Removes min element from min heap and returns it */
int MinHeap ::  extractMin()
{
    if(heap_size>=1){
    int min = harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return min;
    }
    return -1;
}

/* Removes element from position x in the min heap  */
void MinHeap :: deleteKey(int i)
{
    if(i>=heap_size)
        return;
    decreaseKey(i,INT_MIN);
    extractMin();
}

/* Inserts an element at position x into the min heap*/
void MinHeap ::insertKey(int k)
{
if(heap_size<capacity){
    int i=heap_size;
    heap_size++;
    decreaseKey(i,k);
    }
}



// Decrease Key operation, helps in deleting key from heap
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}


/* You may call below MinHeapify function in 
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}


// { Driver Code Starts.


// Driver code
int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
     ll a;
     cin>>a;
     MinHeap h(a);
     for(ll i=0;i<a;i++)
     {
        int c;
        int  n;
        cin>>c;
        if(c==1)
            {  cin>>n;
            
               h.insertKey(n);
             }
        if(c==2)
           {  cin>>n;
              h.deleteKey(n);
	    } 
        if(c==3)
              { 
               cout<<h.extractMin()<<" ";
               }
     
      }
       cout<<endl;
       // delete h.harr;
       h.harr=NULL;
       
   }
  return 0;
  }


  // } Driver Code Ends
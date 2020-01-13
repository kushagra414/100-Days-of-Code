//Based on quick Sort
//Do quick sort then move towards right or left by comparing the index value of k and pivot
//This algo is used to find smallest kth element
//Best time complexity is O(n) and worst is O(n^2)---> In case of already sorted array, where k = last element
#include<iostream>
using namespace std;

//swap algo
int size;
void swap(int *a,int j,int l){
	int temp;
	temp = a[l];
	a[l] = a[j];
	a[j] = temp;
}

//partition algorithm
int partition(int *a, int l, int u){
	int i = l;
	int j = u;
	int L = i;
	while(i<j){
		while(a[i]<=a[L])
		i++;
		while(a[j]>a[L])
		j--;
		if(i<j)
		swap(a, i, j);
		//cout<<"i = "<<i<<", j = "<<j<<", L = "<<L<<endl;
	}
	swap(a, j, L);
	//cout<<"After swap, j = "<<j<<endl;
	return j;
}

int quickselection(int *a, int l, int u, int k){
	if(k){
		//cout<<"l = "<<l<<", u = "<<u<<endl;
	int pivot = partition(a, l, u);
	if(pivot+1==k)
	return pivot;
	else if(k>pivot+1){
	l = pivot+1;
	quickselection(a, l, u, k);
}
	else if(k<pivot+1){
	u = pivot-1;
	quickselection(a, l, u, k);
}
}
else
return -1;
}

int main(){
	int test;
	cin>>test;
	while(test){
		cin>>size;
		int a[size];
		for(int i=0;i<size;i++)
		cin>>a[i];
		int k;
		cin>>k;
		int index = quickselection(a, 0, size-1, k);
		//cout<<"index = "<<index<<", "<<a[index]<<endl;
		//for(int i=0;i<size;i++)
		//cout<<a[i]<<" ";
		cout<<a[index]<<endl;
		test--;
	}
	return 0;
}
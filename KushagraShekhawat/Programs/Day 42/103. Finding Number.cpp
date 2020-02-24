#include<iostream>
using namespace std;
int key, size, pivot;
int bs(int *ptr, int end, int start){
	int mid = (start+end)/2;
	if(end>=start){
		if(ptr[mid]>key)
		bs(ptr, mid-1, start);
		else if(ptr[mid]<key)
		bs(ptr, end, mid+1);
		else
		return mid;
	}
	else{
	return -1;
}
}
int bs1(int *ptr, int end, int start){
	int mid = (start+end)/2;
	if(end>=start){
		if(ptr[mid]>key)
		bs1(ptr, end, mid+1);
		else if(ptr[mid]<key)
		bs1(ptr, mid-1, start);
		else
		return mid;
	}
	else{
	return -1;
}
}
int pivot_fn(int *ptr){
	int i=0;
	for(i =0; i<size-1; i++){
		if(ptr[i]>ptr[i+1]){
		return i;
	}
	}
	return -1;
}
int main(){
	int test, pos =-1;
	cin>>test;
	while(test){
		cin>>size;
		int a[size];
		for(int i =0; i<size; i++)
		cin>>a[i];
		cin>>key;
		pivot = pivot_fn(a);
		if(pivot == -1)
		pos = bs(a, size-1, 0);
		else{
		pos = bs(a, pivot, 0);
		if(pos == -1)
		pos = bs1(a, size-1, pivot+1);
	}
		cout<<pos<<endl;
		test--;
	}
	return 0;
}
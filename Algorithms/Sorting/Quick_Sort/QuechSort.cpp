#include<bits/stdc++.h>
using namespace std;
int partion(int*& arr,int l,int h){
	int i = l,j=h,pi=arr[l];
	while(i < j){
		while(i <= h && arr[i] <= pi){
			i++;
		}
		while(j >= l && arr[j] > pi){
			j--;
		}
		if(i < j){
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[l],arr[j]);  // place pivot to correct position , arr[j] ensure that all elements before pivot <= pivot
	return j;
}
void queckSort(int* arr,int l,int h){
	if(l < h){
		int pivot = partion(arr,l,h);
		queckSort(arr,l,pivot -1);
		queckSort(arr,pivot +1 ,h);
	}
}
int main(){
int arr[17] = {1,7,3,5,9,3,5,6,7,88,99,90,34,21,34,23,564};
	cout<<"before sorting  : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	cout<<'\n';
	int sz = sizeof(arr)/sizeof(arr[0]);
	queckSort(arr,0,sz-1);
	cout<<"after sorting  : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	return 0;
}
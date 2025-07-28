#include<bits/stdc++.h>
using namespace std;
int iteration = 0;
void mergeSort(int* arr,int low,int mid,int high){
	int i=low,j=mid+1,k=0;
	int sz= high - low + 1;
	int* c = new int[sz];
	while(i <= mid && j <= high){
		if(arr[i] < arr[j]){
			c[k++]=arr[i++];
		}else{
			c[k++]=arr[j++];
		}
	}
	while(i <= mid){
		c[k++] = arr[i++];
	}
	while(j <= high){
		c[k++] = arr[j++];
	}
	for(int i = 0 ; i < sz ; i++){
		arr[i+low]=c[i];
	}
	delete []c;
}
void split(int* arr,int low,int high){
	if(low < high){
		int mid = (low+ high) / 2;
		split(arr,low,mid);
		split(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
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
	split(arr,0,sz-1);
	cout<<"after sorting  : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	

	return 0;
}
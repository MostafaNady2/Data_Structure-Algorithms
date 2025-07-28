#include<bits/stdc++.h>
using namespace std;
int iteration = 0;
void insertionSort(int* arr,int n){
	for(int i = 1 ; i < n ; i++){
		int j=i-1;
		int ele = arr[i];
		while(j >= 0 && arr[j] > ele){
			iteration++;
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1] = ele;
	}
}
int main(){
	int arr[17] = {1,7,3,5,9,3,5,6,7,88,99,90,34,21,34,23,564};
	cout<<"before sorting  : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	cout<<'\n';
	insertionSort(arr,17);
	cout<<"after sorting  : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	cout<<"\nit takes " << iteration <<" operations";
	return 0;
}


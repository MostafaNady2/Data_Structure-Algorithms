#include<bits/stdc++.h>
using namespace std;
int iteration = 0;
void bubbleSort(int* arr,int n){
	bool inversion = true;
	for(int i = 0;i < n ; i++){
		inversion = false;
		for(int j = i+1 ; j < n ; j++){
			if(arr[j] < arr[j-1]){
				swap(arr[j],arr[j-1]);
				inversion = true;
			}
			iteration++;
		}
		if(!inversion){
			return;
		}
	}
}
int main(){
	int arr[17] = {1,7,3,5,9,3,5,6,7,88,99,90,34,21,34,23,564};
	cout<<"before sorting  : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	cout<<'\n';
	bubbleSort(arr,17);
	cout<<"after sorting  : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	cout<<"\nit takes " << iteration <<" operations";
	return 0;
}
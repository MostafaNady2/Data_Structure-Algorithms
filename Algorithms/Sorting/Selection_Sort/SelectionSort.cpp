#include<bits/stdc++.h>
using namespace std;
int iteration=0;
void selectionSort(int* arr,int n){
	for(int i = 0 ; i < n;i++){
		int min=i;
		for(int j = i+1; j < n;j++){
			if(arr[j] < arr[min]){
				min = j;
			}
			iteration++;
		}
		swap(arr[i],arr[min]);
	}
}
int main(){

	int arr[17] = {1,7,3,5,9,3,5,6,7,88,99,90,34,21,34,23,564};
	cout<<"before sorting : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	cout<<'\n';
	selectionSort(arr,17);
	cout<<"after sorting : ";
	for(int e : arr){
		cout<<e<<" ";
	}
	cout<<"\nit takes "<<iteration <<" iterations";

	return 0;
}
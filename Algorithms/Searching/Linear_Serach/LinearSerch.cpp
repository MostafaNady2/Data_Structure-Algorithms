#include<bits/stdc++.h>
using namespace std;
int search(int* arr,int n,int ele){
	
	for(int i = 0 ; i < n ; i++){
		if(arr[i] == ele){
			return i;
		}
	}
	return 0;
}
int main(){
	int arr[20]={1,5,7,45,6,32,45,90 ,86,411,10,690,4,3,22,89,65,435,80,100};
	
	cout<<"searching on 20 : ";
	if(search(arr,20,20)){
		cout<<"element: "<<20 << " found at index : "<<search(arr,20,20)<<'\n';
	}else{
		cout<<"the element 20 not fount\n";
	}

	cout<<"searching on 45 : ";
	if(search(arr,20,45)){
		cout<<"element: "<<45 << " found at index : "<<search(arr,20,45)<<'\n';
	}else{
		cout<<"the element 45 not fount\n";
	}

	cout<<"searching on 3 : ";
	if(search(arr,20,3)){
		cout<<"element: "<<3 << " found at index : "<<search(arr,20,3)<<'\n';
	}else{
		cout<<"the element 3 not fount\n";
	}

	cout<<"searching on 0 : ";
	if(search(arr,20,0)){
		cout<<"element: "<<0 << " found at index : "<<search(arr,20,0)<<'\n';
	}else{
		cout<<"the element 0 not fount\n";
	}

	return 0;
}
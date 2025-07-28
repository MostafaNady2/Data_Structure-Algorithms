
public class MergeSort {
	public static void main(String[] args) {
		int arr[] = { 1, 7, 3, 5, 9, 3, 5, 6, 7, 88, 99, 90, 34, 21, 34, 23, 564 };
		System.out.print("before sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
		System.out.println();
		split(arr,0, arr.length-1);
		System.out.print("after sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
	}
	public static void mergeSort(int[] arr,int low,int mid,int high){
		int i = low,j= mid+1,k=0,sz =high - low +1;
		int[] c = new int[sz];
		while(i <= mid && j <= high){
			if(arr[i] < arr[j]){
				c[k++] = arr[i++];
			}else{
				c[k++]=arr[j++];
			}
		}
		while(i <= mid){
			c[k++]=arr[i++];
		}
		while (j <= high) {
			c[k++] = arr[j++];
		}
		for(i = 0 ; i < sz ; i++){
			arr[i+low] = c[i];
		}
	}
	public static void split(int[] arr,int low,int high){
		if(low  < high){
			int mid = (low + high) /2;
			split(arr, low, mid);
			split(arr, mid+1, high);
			mergeSort(arr,low,mid,high);
		}
	}
}

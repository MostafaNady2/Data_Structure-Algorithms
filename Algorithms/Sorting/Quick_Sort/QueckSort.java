class QueckSort {
	public static void main(String[] args) {
		int arr[] = { 1, 7, 3, 5, 9, 3, 5, 6, 7, 88, 99, 90, 34, 21, 34, 23, 564 };
		System.out.print("before sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
		System.out.println();
		queckSort(arr,0, arr.length-1);
		System.out.print("after sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
	}
	private static int partion(int[] arr,int l,int h){
		int i = l, j = h ,pi = arr[l];
		int t;
		while(i < j){
			while(i <= h && arr[i] <= pi){
				i++;
			}
			while( j >= l && arr[j] > pi){
				j--;
			}
			if(i < j){
				t = arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
		t= arr[l];
		arr[l]=arr[j];
		arr[j]=t;
		return j;
	} 
	public static void queckSort(int[] arr,int l,int h){
		if( l < h){
			int pivot = partion(arr, l, h);
			queckSort(arr, l, pivot-1);
			queckSort(arr, pivot+1, h);
		}
	}
	
}
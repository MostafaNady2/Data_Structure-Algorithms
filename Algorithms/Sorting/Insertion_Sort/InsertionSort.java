
public class InsertionSort {
	private static int iteration = 0;
	public static void main(String[] args) {
		int arr[] = { 1, 7, 3, 5, 9, 3, 5, 6, 7, 88, 99, 90, 34, 21, 34, 23, 564 };
		System.out.print("before sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
		System.out.println();
		insertionSort(arr, arr.length);
		System.out.print("after sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
		System.out.println("\nit takes "+ iteration + " iterations");
	}
	public static void insertionSort(int[] arr,int n){
		for(int i = 1; i < n ;i++){
			int ele = arr[i];
			int j = i-1;
			while(j >= 0 && arr[j] > ele){
				iteration++;
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = ele;
		}
	}
	
}

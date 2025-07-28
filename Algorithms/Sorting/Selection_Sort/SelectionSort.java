public class SelectionSort {
	private static int iteration = 0;

	public static void main(String[] args) {
		int arr[] = { 1, 7, 3, 5, 9, 3, 5, 6, 7, 88, 99, 90, 34, 21, 34, 23, 564 };
		System.out.print("before sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
		System.out.println();
		selectionSort(arr, arr.length);
		System.out.print("after sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
		System.out.println("\nit takes "+ iteration + " iterations");
	}

	public static void selectionSort(int[] arr, int n) {
		for (int i = 0; i < n; i++) {
			int min = i;
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < arr[min]) {
					min = j;
				}
				iteration++;
			}
			int t = arr[i];
			arr[i] = arr[min];
			arr[min] = t;
		}
	}

}
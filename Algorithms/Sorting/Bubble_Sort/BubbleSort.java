public class BubbleSort {
	private static int iteration = 0;

	public static void main(String[] args) {
		int arr[] = { 1, 7, 3, 5, 9, 3, 5, 6, 7, 88, 99, 90, 34, 21, 34, 23, 564 };
		System.out.print("before sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
		System.out.println();
		bubbleSort(arr, arr.length);
		System.out.print("after sorting : ");
		for (int e : arr) {
			System.out.print(e + " ");
		}
		System.out.println("\nit takes "+ iteration + " iterations");
	}

	public static void bubbleSort(int[] arr, int n) {
		int t;
		boolean inversion = true;
		for (int i = 0; i < n; i++) {
			inversion = false;
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < arr[j - 1]) {
					t = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = t;
					inversion = true;
				}
				iteration++;
			}
			if(!inversion){
				return;
			}
		}
	}
}

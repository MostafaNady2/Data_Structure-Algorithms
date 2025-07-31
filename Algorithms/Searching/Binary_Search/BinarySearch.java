

public class BinarySearch {
	public static void main(String[] args) {
		int []arr={3,6,7,9,10,50,67};
		int ele =20;
		System.out.print("searching on "+ele+" : ");
		if(binarySearch(arr,arr.length, ele)!=-1){
			System.out.println("founded at index  : "+binarySearch(arr,arr.length, ele));
		}else{
			System.out.println("not found");
		}
		ele =10;
		System.out.print("searching on "+ele+" : ");
		if(binarySearch(arr,arr.length, ele)!=-1){
			System.out.println("founded at index  : "+binarySearch(arr, arr.length,ele));
		}else{
			System.out.println("not found");
		}
		ele =3;
		System.out.print("searching on "+ele+" : ");
		if(binarySearch(arr,arr.length, ele)!=-1){
			System.out.println("founded at index  : "+binarySearch(arr,arr.length, ele));
		}else{
			System.out.println("not found");
		}
	}
	public static int binarySearch(int[] arr ,int n,int ele){
		int i = 0;
		int j = n-1;
		while(i <= j){
			int mid = (i+j)/2;
			if(arr[mid]==ele){
				return mid;
			}else if(ele > arr[mid]){
				i=mid+1;
			}else{
				j=mid-1;
			}
		}
		return -1;
	}
}

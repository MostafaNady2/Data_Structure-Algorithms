public class Main {
	public static void main(String[] args) {
		HashMap<Integer, String> map = new HashMap<>();
		map.put(1, "abc");
		map.put(2, "def");
		map.put(3, "ghi");
		map.put(4, "jkl");
		map.put(5, "mno");

		System.out.println("----------------- testing get -----------------");
		System.out.println("get 1 : "+map.get(1));
		System.out.println("get 2 : "+map.get(2));
		System.out.println("get 3 : "+map.get(3));
		System.out.println("get 8 (not in map): "+map.get(8));
		
		System.out.println("----------------- testing remove -----------------");
		System.out.println("size : "+map.size());
		map.remove(1);
		System.out.println("size after removing 1 : "+map.size());
		
		System.out.println("----------------- testing get deleted key -----------------");
		System.out.println("get 1 (deleted) : "+map.get(1));
		
		System.out.println("----------------- testing isEmpty -----------------");
		System.out.println("is empty : "+(map.isEmpty() ? "true": "false"));
		
		System.out.println("----------------- testing clear -----------------");
		map.clear();
		System.out.println("is empty : "+(map.isEmpty() ? "true": "false"));

	}
}

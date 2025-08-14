public class Main {
	public static void main(String[] args) {
		HashSet<String> set = new HashSet<>();
		set.put("abc");
		set.put("def");
		set.put("ghi");
		set.put("jkl");
		set.put("mno");

		System.out.println("----------------- testing get -----------------");
		System.out.println("get abs : "+set.get("abc"));
		System.out.println("get def : "+set.get("def"));
		System.out.println("get ghi : "+set.get("ghi"));
		System.out.println("get pqr (not in set): "+set.get("pqr"));
		
		System.out.println("----------------- testing remove -----------------");
		System.out.println("size : "+set.size());
		set.remove("abc");
		System.out.println("size after removing abc : "+set.size());
		
		System.out.println("----------------- testing get deleted key -----------------");
		System.out.println("get abc (deleted) : "+set.get("abc"));
		
		System.out.println("----------------- testing isEmpty -----------------");
		System.out.println("is empty : "+(set.isEmpty() ? "true": "false"));
		
		System.out.println("----------------- testing clear -----------------");
		set.clear();
		System.out.println("is empty : "+(set.isEmpty() ? "true": "false"));

	}
}


import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class HuffmanCoding {
	private Node root;
	private String s;
	private Map<Character , String> codes = new HashMap<>();
	private void store(String s){
		this.s = s;
		Map<Character, Integer> m = new HashMap<>();
		for(char c : s.toCharArray()){
			m.put(c , m.getOrDefault(c , 0) + 1);
		}
		PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(Node::getCount));
		for(char c : m.keySet()){
			pq.add(new Node(c , m.get(c)));
		}
		while(pq.size() > 1){
			Node a = pq.poll();
			Node b = pq.poll();
			Node c = new Node('\0' , a.count + b.count);
			c.left = a;
			c.right = b;
			pq.add(c);
		}
		this.root = pq.poll();
	}
	private void storeCode(Node node , String s){
		if(node.left == null && node.right == null){
			codes.put(node.c , s);
			return;
		}
		storeCode(node.left , s + '0');
		storeCode(node.right , s + '1');
	}
	public void encode(String s){
		this.s = s;
		store(s);
		storeCode(root , "");
	}
	public void compressionStats(){
		System.out.println("string before compression : " + s.length()*8 + " bits");
		int compressed = 0;
		Map<Character,Integer> f = new HashMap<>();
		for(char c : s.toCharArray()){
			f.put(c , f.getOrDefault(c , 0) + 1);
		}
		for(char c : codes.keySet()){
			compressed += codes.get(c).length() * f.get(c);
		}
		System.out.println("string after compression : " + compressed + " bits , "+"table size : " + codes.size() * 8 + " bits");
		System.out.println("total : " + (compressed + (codes.size() * 8)) + " bits");
		System.out.println("compression ratio : " + (double) s.length()*8 / compressed);
	}
	public void printCodes(){
		System.out.println("-------- codes --------");
		for(char c : codes.keySet()){
			System.out.println(c + " : " + codes.get(c));
		}
		System.out.println("----------------");
	}
}
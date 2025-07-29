
public class Node {
	char c;
	int count;
	Node left;
	Node right;
	Node(char c , int count) {
		this.c = c;
		this.count = count;
		this.left = null;
		this.right = null;
	}
	public int getCount() {
		return this.count;
	}
	
}

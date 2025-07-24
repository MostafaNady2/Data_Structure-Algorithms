class Node<T> {
	T val;
	Node<T> left;
	Node<T> right;
	int height;
	public Node(T val){
		this.val = val;
		left = null;
		right = null;
		height = 1;
	}
}
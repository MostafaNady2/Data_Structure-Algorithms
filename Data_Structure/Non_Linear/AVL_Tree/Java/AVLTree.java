public class AVLTree<T extends Comparable<T>> {
	private Node<T> root;

	private int compare(T val1, T val2) {
		return val1.compareTo(val2);
	}

	private int height(Node<T> node) {
		if (node == null) {
			return 0;
		}
		return node.height;
	}

	int balanceFactor(Node<T> node) {
		if (node == null) {
			return 0;
		}
		return height(node.left) - height(node.right);
	}

	private Node<T> rightRotate(Node<T> node) {
		if (node == null || node.left == null) {
			return null;
		}
		Node<T> mid = node.left;
		Node<T> right = mid.right;

		mid.right = node;
		node.left = right;

		node.height = Math.max(height(node.left), height(node.right)) + 1;
		mid.height = Math.max(height(mid.left), height(mid.right)) + 1;

		return mid;
	}

	private Node<T> leftRotate(Node<T> node) {
		if (node == null || node.right == null) {
			return null;
		}
		Node<T> mid = node.right;
		Node<T> left = mid.left;

		mid.left = node;
		node.right = left;

		node.height = Math.max(height(node.left), height(node.right)) + 1;
		mid.height = Math.max(height(mid.left), height(mid.right)) + 1;

		return mid;
	}

	private Node<T> getMax(Node<T> base) {
		Node<T> curr = base;
		while (curr.right != null) {
			curr = curr.right;
		}
		return curr;
	}

	private Node<T> getMin(Node<T> base) {
		Node<T> curr = base;
		while (curr.left != null) {
			curr = curr.left;
		}
		return curr;
	}

	private Node<T> insert(Node<T> node, T val) {
		if (node == null) {
			return new Node<>(val);
		}
		if (compare(val, node.val) > 0) {
			node.right = insert(node.right, val);
		} else if (compare(val, node.val) < 0) {
			node.left = insert(node.left, val);
		}

		node.height = Math.max(height(node.left), height(node.right)) + 1;
		int bf = balanceFactor(node);

		if (bf > 1 && node.left != null && compare(val, node.left.val) < 0) {  // left left 
			node = rightRotate(node);
		}
		else if (bf < 0 && node.right != null && compare(val, node.right.val) > 0) {  // right right
			node = leftRotate(node);
		}
		else if (bf > 1 && node.left != null && compare(val, node.left.val) > 0) {  // left right
			node.left = leftRotate(node.left);
			node = rightRotate(node);
		}
		else if (bf < 0 && node.right != null && compare(val, node.right.val) < 0) {  // right left
			node.right = rightRotate(node.right);
			node = leftRotate(node);
		}
		return node;
	}

	private Node<T> remove(Node<T> node, T val) {
		if (node == null) {
			return null;
		}
		if (compare(val, node.val) > 0) {
			node.right = remove(node.right, val);
		} else if (compare(node.val, val) > 0) {
			node.left = remove(node.left, val);
		} else {
			if (node.left == null && node.right == null) {
				return null;
			} else if (node.left != null && node.right != null) {
				node.val = getMin(node.right).val;
				node.right = remove(node.right, node.val);
			} else {
				if (node.right == null) {
					node = node.left;
				} else {
					node = node.right;
				}
			}
		}

		node.height = Math.max(height(node.left), height(node.right)) + 1;
		int bf = balanceFactor(node);

		if (bf > 1 && balanceFactor(node.left) >= 0) { // heavy left
			node = rightRotate(node);
		}
		if (bf < 0 && balanceFactor(node.right) <= 0) { // heavy right
			node = leftRotate(node);
		}
		if (bf > 1 && balanceFactor(node.left) < 0) { // heavy in right of left subtree
			node.left = leftRotate(node.left);
			node = rightRotate(node);
		}
		if (bf < 0 && balanceFactor(node.right) > 0) { // heavy in left of right subtree
			node.right = rightRotate(node.right);
			node = leftRotate(node);
		}
		return node;
	}

	private void deleteTree(Node<T> node) {
		if (node == null) {
			return;
		}
		deleteTree(node.left);
		deleteTree(node.right);
		node = null;
	}

	private void printTree(Node<T> node) {
		if (node == null) {
			return;
		}
		printTree(node.left);
		System.out.print(node.val + " ");
		printTree(node.right);
	}

	public AVLTree() {
		this.root = null;
	}

	public boolean find(T val) {
		Node<T> curr = root;
		while (curr != null) {
			if (compare(val, curr.val) > 0) {
				curr = curr.right;
			} else if (compare(val, curr.val) < 0) {
				curr = curr.left;
			} else {
				return true;
			}
		}
		return false;
	}

	public void insert(T val) {
		root = insert(root, val);
	}

	public T getMinVal() {
		if (isEmpty()) {
			return null;
		}
		return getMin(root).val;
	}

	public T getMaxVal() {
		if (isEmpty()) {
			return null;
		}
		return getMax(root).val;
	}

	public boolean remove(T val) {
		if (!find(val)) {
			return false;
		}
		root = remove(root, val);
		return true;
	}

	public boolean isEmpty() {
		return root == null;
	}

	public void clear() {
		if (isEmpty()) {
			return;
		}
		deleteTree(root);
		root = null;
	}

	public void print() {
		printTree(root);
	}

}
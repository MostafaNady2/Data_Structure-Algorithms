public class BinarySearchTree<T extends Comparable<T>> {
	private Node<T> root;

	public BinarySearchTree() {
		this.root = null;
	}

	private int compare(T a, T b) {
		return a.compareTo(b);
	}

	private Node<T> getMin(Node<T> base) {
		Node<T> curr = base;
		while (curr.left != null) {
			curr = curr.left;
		}
		return curr;
	}

	private Node<T> getMax(Node<T> base) {
		Node<T> curr = base;
		while (curr.right != null) {
			curr = curr.right;
		}
		return curr;
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

	public Node<T> remove(Node<T> base, T val) {
		if (base == null) {
			return null;
		}
		if (compare(val, base.val) > 0) {
			base.right = remove(base.right, val);
		} else if (compare(val, base.val) < 0) {
			base.left = remove(base.left, val);
		} else {
			if (base.left == null && base.right == null) {
				base = null;
			} else if (base.left != null && base.right != null) {
				base.val = getMin(base.right).val;
				base.right = remove(base.right, base.val);
			} else if (base.right == null || base.left == null) {
				if (base.right == null) {
					base = base.left;
				} else {
					base = base.right;
				}
			} else {
				return base;
			}
		}
		return base;
	}

	public boolean remove(T val) {
		if (!find(val)) {
			return false;
		}
		root = remove(root, val);
		return true;
	}

	public T getMinVal() {
		return getMin(this.root).val;
	}

	public T getMaxVal() {
		return getMax(this.root).val;
	}

	public void clear() {
		if (!isEmpty()) {
			deleteTree(this.root);
			root = null;
		}
	}

	public void insert(T val) {
		if (this.root == null) {
			root = new Node<T>(val);
			return;
		}
		Node<T> curr = this.root;
		Node<T> parent = null;
		while (curr != null) {
			parent = curr;
			if (compare(val, curr.val) > 0) {
				curr = curr.right;
			} else {
				curr = curr.left;
			}
		}
		if (compare(val, parent.val) > 0) {
			parent.right = new Node<T>(val);
		} else {
			parent.left = new Node<T>(val);
		}
	}

	public boolean find(T val) {
		Node<T> curr = this.root;
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

	public boolean isEmpty() {
		return this.root == null;
	}

	public void print() {
		printTree(this.root);
	}

}

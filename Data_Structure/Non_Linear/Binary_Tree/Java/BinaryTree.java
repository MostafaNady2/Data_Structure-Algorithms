import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree<T> {
    private Node<T> root;
    public BinaryTree() {
        this.root = null;
    }
    public void insert(T val) {
        if (this.root == null) {
            this.root = new Node<T>(val);
            return;
        }
        Queue<Node<T>> q = new LinkedList<Node<T>>();
        q.add(this.root);
        while (!q.isEmpty()) {
            Node<T> temp = q.remove();
            if (temp.left == null) {
                temp.left = new Node<T>(val);
                return;
            } else {
                q.add(temp.left);
            }
            if (temp.right == null) {
                temp.right = new Node<T>(val);
                return;
            } else {
                q.add(temp.right);
            }
        }
    }
    public void preOrderPrint(Node<T> node) {
        if(node == null){
            return;
        }
        System.out.print(node.val + " ");
        preOrderPrint(node.left);
        preOrderPrint(node.right);
    }
    public void inOrderPrint(Node<T> node) {
        if(node == null){
            return;
        }
        inOrderPrint(node.left);
        System.out.print(node.val + " ");
        inOrderPrint(node.right);
    }
    public void postOrderPrint(Node<T> node) {
        if(node == null){
            return;
        }
        postOrderPrint(node.left);
        postOrderPrint(node.right);
        System.out.print(node.val + " ");
    }
    public void deleteTree(Node<T> node) {
        if (node == null) {
            return;
        }
        deleteTree(node.left);
        deleteTree(node.right);
        node = null;
    }
    public void preOrderPrint(){
        preOrderPrint(this.root);
    }
    public void inOrderPrint(){
        inOrderPrint(this.root);
    }
    public void postOrderPrint(){
        postOrderPrint(this.root);
    }
	public void BFS(Node<T> node){
		if(node == null){
			return;
		}
		Queue<Node<T>> queue = new LinkedList<>();
		queue.add(node);
		while(!queue.isEmpty()){
			Node<T> curr = queue.remove();
			System.out.print(curr.val + " ");
			if(curr.left != null){
				queue.add(curr.left);
			}
			if(curr.right != null){
				queue.add(curr.right);
			}
		}
	}
	public void bfs(){
		BFS(root);
	}
}
public class Node<T> {
    private T val;
    private Node<T> next;

    public Node(T val) {
        this.val = val;
        this.next = null;
    }

    public T getVal() {
        return val;
    }

    public Node<T> next() {
        return next;
    }
    public void setNext(Node<T> next) {
        this.next = next;
    }
}

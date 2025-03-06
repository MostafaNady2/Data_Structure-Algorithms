public class Node<T> {
    private T val;
    public Node<T> next;

    public Node() {
        this.val = null;
        this.next = null;
    }

    public T getValue() {
        return this.val;
    }

    public void setValue(T val) {
        this.val = val;
    }
}

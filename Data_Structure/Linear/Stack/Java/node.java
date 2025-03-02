public class node<T> {
    private T val;
    node<T> next;

    public node(T val) {
        this.val = val;
        this.next = null;
    }

    public T getValue() {
        return val;
    }
}

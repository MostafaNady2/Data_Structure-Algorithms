public class Queue<T> {
    private Node<T> front;
    private Node<T> back;
    private int count;
    
    public Queue() {
        front = null;
        back = null;
        count = 0;
    }

    public void push(T val) {
        Node<T> newVal = new Node<T>(val);
        newVal.setNext(null);
        if (front == null) {
            front = newVal;
            back = newVal;
        } else {
            back.setNext(newVal);
            back = newVal;
        }
        count++;
    }

    public boolean isEmpty() {
        return front == null;
    }

    public void pop() {
        if (!isEmpty()) {
            Node<T> last = front;
            front = front.next();
            last = null;
            count--;
        }
    }

    public T getFront() {
        if (!isEmpty()) {
            return front.getVal();
        } else {
            throw new IllegalStateException("No front");
        }
    }

    public T getBack() {
        if (!isEmpty()) {
            return back.getVal();
        } else {
            throw new IllegalStateException("No back");
        }
    }

    public int size() {
        return count;
    }

    public void print() {
        if (!isEmpty()) {
            Node<T> start = front;
            while (start != null) {
                System.out.println(start.getVal());
                start = start.next();
            }
        }
    }

    public void clear() {
        while (front != null) {
            Node<T> node = front;
            front = front.next();
            node = null;
        }
        back = null;
        count = 0;
    }

    public int find(T val) {
        Node<T> start = front;
        int index = 0;
        while (start != null) {
            if (start.getVal().equals(val)) {
                return index;
            }
            start = start.next();
            index++;
        }
        return -1;
    }

}

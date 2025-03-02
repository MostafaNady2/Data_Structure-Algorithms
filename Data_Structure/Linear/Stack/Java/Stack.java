class Stack<T>{
    private node<T> top;
    private int count;
    
    public Stack() {
        top = null;
        count = 0;
    }
    
    public void push(T val) {
        node<T> newVal = new node<T>(val);
        newVal.next = top;
        top = newVal;
        count++;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public void pop() {
        if (!isEmpty()) {
            node<T> last = top;
            top = top.next;
            last.next = null;  
            count--;
        }
    }

    public int size() {
        return count;
    }
    public T getTop() {
        return top.getValue();
    }
    public void print() {
        node<T> start = top;
        while (start!= null) {
            System.out.println(start.getValue());
            start = start.next;
        }
    }
}
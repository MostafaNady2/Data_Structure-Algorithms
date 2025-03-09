public class LinkedList<T extends Comparable<T>> {
    private Node<T> head;
    private Node<T> tail;
    private int count;

    public LinkedList() {
        head = null;
        tail = null;
        count = 0;
    }

    public void pushBack(T val) {
        Node<T> newVal = new Node<T>();
        newVal.setValue(val);
        if (tail == null) {
            tail = newVal;
            head = newVal;
        } else {
            tail.next = newVal;
            tail = newVal;
        }
        count++;
    }

    public void pushFront(T val) {
        Node<T> newVal = new Node<T>();
        newVal.setValue(val);
        if (head == null) {
            tail = newVal;
            head = newVal;
        } else {
            newVal.next = head;
            head = newVal;
        }
        count++;
    }

    public boolean isEmpty() {
        return count == 0;
    }

    public boolean contains(T val) {
        Node<T> start = head;
        while (start != null) {
            if (start.getValue().equals(val)) {
                return true;
            }
            start = start.next;
        }
        return false;
    }

    public void sortAsc() {
        Node<T> first = head;
        Node<T> second = head;
        T temp;
        while (first != null) {
            second = first.next;
            while (second != null) {
                if (first.getValue().compareTo(second.getValue()) > 0) {
                    temp = first.getValue();
                    first.setValue(second.getValue());
                    second.setValue(temp);
                }
                second = second.next;
            }
            first = first.next;
        }
        first = null;
        second = null;
    }

    public void sortDesc() {
        Node<T> first = head;
        Node<T> second = head;
        T temp;
        while (first != null) {
            second = first.next;
            while (second != null) {
                if (first.getValue().compareTo(second.getValue()) < 0) {
                    temp = first.getValue();
                    first.setValue(second.getValue());
                    second.setValue(temp);
                }
                second = second.next;
            }
            first = first.next;
        }
        first = null;
        second = null;
    }

    public void popBack() {
        if (count == 0) {
            return;
        }
        if (count == 1) {
            head = null;
            tail = null;
            count = 0;
            return;
        }
        Node<T> start = head;
        while (start.next != tail) {
            start = start.next;
        }
        tail = start;
        tail.next = null;
        count--;
    }

    public void popFront() {
        if (count == 0) {
            return;
        }
        if (count == 1) {
            head = null;
            tail = null;
            count = 0;
            return;
        }
        Node<T> node = head;
        head = head.next;
        node.next = null;
        count--;
    }

    public void print() {
        Node<T> start = head;
        System.out.print("[");
        while (start != null) {
            System.out.print(start.getValue() + " ");
            start = start.next;
        }
        System.out.println("]");
    }

    public int size() {
        return count;
    }

    public void insertAt(int index, T val) {
        if (index < 0 || index >= count) {
            return;
        }
        if (index == 0) {
            pushFront(val);
            return;
        }
        if (index == count) {
            pushBack(val);
            return;
        }
        Node<T> start = head;
        index--;
        while (index > 0) {
            start = start.next;
            index--;
        }
        Node<T> newVal = new Node<T>();
        newVal.setValue(val);
        newVal.next = start.next;
        start.next = newVal;
        count++;
    }

    public void deleteAt(int index) {
        if (index < 0 || index >= count) {
            return;
        }
        if (index == 0) {
            popFront();
            return;
        }
        if (index == count) {
            popBack();
            return;
        }
        Node<T> start = head;
        index--;
        while (index > 0) {
            start = start.next;
            index--;
        }
        Node<T> del = start.next;
        start.next = del.next;
        del = null;
        count--;
    }

    public void reverse() {
        Node<T> curr = head;
        Node<T> next = curr.next;
        Node<T> prev = null;
        Node<T> newTail = head;
        while (next != null) {
            curr.next = prev;
            prev = curr;
            curr = next;
            next = next.next;
        }
        curr.next = prev;
        head = curr;
        tail = newTail;
    }
    public void clear() {
        // Thanks to Garbage Collector 
        head = null;
        tail = null;
        count = 0;
    }
}

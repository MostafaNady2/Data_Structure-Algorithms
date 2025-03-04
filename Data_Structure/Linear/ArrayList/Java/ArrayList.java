public class ArrayList<T> {
    private T[] arr;
    private int maxSize;
    private int actualSize;
    @SuppressWarnings("unchecked")
    public ArrayList(int size) {
        if (size > 0) {
            maxSize = size;
            actualSize = 0;
            arr = (T[]) new Object[maxSize];
        } else {
            System.out.println("Invalid size");
            maxSize = 0;
            actualSize = 0;
            arr = null;
        }
    }

    public void insertAt(int index, T val) {
        if (index < 0 || index >= maxSize) {
            System.out.println("Invalid index");
        } else if (isFull()) {
            System.out.println("ArrayList is full");
        } else {
            for (int i = actualSize; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = val;
            actualSize++;
        }
    }

    public boolean isFull() {
        return actualSize == maxSize;
    }

    public boolean isEmpty() {
        return actualSize == 0;
    }

    public void removeAt(int index) {
        if (index < 0 || index >= actualSize) {
            System.out.println("Invalid index");
        } else if (isEmpty()) {
            System.out.println("ArrayList is Empty");
        } else {
            for (int i = index; i < actualSize - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[actualSize - 1] = null;
            actualSize--;
        }
    }

    public T get(int index) {
        if (index < 0 || index >= actualSize) {
            System.out.println("Invalid index");
            return null;
        } else {
            return arr[index];
        }
    }

    public void clear() {
        for (int i = 0; i < actualSize; i++) {
            arr[i] = null;
        }
        actualSize = 0;
    }

    public int size() {
        return actualSize;
    }

    public int find(T val) {
        for (int i = 0; i < actualSize; i++) {
            if (arr[i].equals(val)) {
                return i;
            }
        }
        return -1;
    }

    public void pushBack(T val) {
        if (isFull()) {
            System.out.println("ArrayList is full");
        } else {
            arr[actualSize] = val;
            actualSize++;
        }
    }

    public void set(int index, T val) {
        if(index < 0 || index >= actualSize) {
            System.out.println("Invalid index");
        } else {
            arr[index] = val;
        }
    }

}

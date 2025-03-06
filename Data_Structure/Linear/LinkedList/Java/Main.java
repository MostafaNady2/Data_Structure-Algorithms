public class Main {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();

        list.pushBack(10);
        list.pushBack(20);
        list.pushBack(30);
        System.out.print("After pushBack: ");
        list.print();

        list.pushFront(5);
        list.pushFront(1);
        System.out.print("After pushFront: ");
        list.print();

        System.out.println("Size: " + list.size());

        System.out.println("Is empty: " + (list.isEmpty() ? "true" : "false"));

        System.out.println("Contains 10: " + (list.contains(10) ? "true" : "false"));
        System.out.println("Contains 15: " + (list.contains(15) ? "true" : "false"));

        list.sortAsc();
        System.out.print("After ascending sort: ");
        list.print();

        list.sortDesc();
        System.out.print("After descending sort: ");
        list.print();

        list.popBack();
        System.out.print("After popBack: ");
        list.print();

        list.popFront();
        System.out.print("After popFront: ");
        list.print();

        System.out.print("Inserting 25 at index 2: ");
        list.insertAt(2, 25);
        list.print();

        System.out.print("Inserting 50 at index 0: ");
        list.insertAt(0, 50);
        list.print();

        System.out.print("Inserting 5 at index " + list.size() + " (end of list): ");
        list.insertAt(list.size(), 5);
        list.print();

        System.out.print("Deleting element at index 2: ");
        list.deleteAt(2);
        list.print();

        System.out.print("Deleting element at index 0: ");
        list.deleteAt(0);
        list.print();

        System.out.print("Deleting last element: ");
        list.deleteAt(list.size() - 1);
        list.print();

        list.clear();
        System.out.println("After clear, isEmpty: " + (list.isEmpty() ? "true" : "false"));
    }
}

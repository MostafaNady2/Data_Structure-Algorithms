public class Main {
    public static void main(String[] args) {
        AVLTree<Integer> bst = new AVLTree<>();

        System.out.println("\nInserting values: 5, 3, 7, 2, 4, 6, 8");
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(2);
        bst.insert(4);
        bst.insert(6);
        bst.insert(8);

        System.out.print("Initial Tree (in-order): ");
        bst.print();

        System.out.println("\n----- Removing 3 (node with one child) -----");
        bst.remove(3);
        System.out.print("Tree after removing 3: ");
        bst.print();

        System.out.println("\n----- Removing 5 (node with two children) -----");
        bst.remove(5);
        System.out.print("Tree after removing 5: ");
        bst.print();

        System.out.println("\n----- Removing 7 (node with one child) -----");
        bst.remove(7);
        System.out.print("Tree after removing 7: ");
        bst.print();

        System.out.println("\nInserting values: 3, 5, 10");
        bst.insert(3);
        bst.insert(5);
        bst.insert(10);
        System.out.print("Tree after re-inserting 3, 5, 10: ");
        bst.print();

        System.out.println("\ngetMin / getMax after re-insertions");
        System.out.println("Minimum value: " + bst.getMinVal());
        System.out.println("Maximum value: " + bst.getMaxVal());

        System.out.println("\ntest find a value");
        System.out.println("Find 3: " + (bst.find(3) ? "true" : "false"));
        System.out.println("Find 6: " + (bst.find(6) ? "true" : "false"));
        System.out.println("Find 9: " + (bst.find(9) ? "true" : "false"));

        System.out.println("------------- test clear tree -------------");
        bst.clear();
        System.out.println("Tree after clear: ");
        bst.print();
        System.out.println("tree is empty: " + (bst.isEmpty() ? "true" : "false"));
    }
}

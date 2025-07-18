public class Main {
    public static void main(String[] args) {
        BinaryTree<Integer> bt = new BinaryTree<>();
        bt.insert(1);
        bt.insert(2);
        bt.insert(3);
        bt.insert(4);
        bt.insert(5);
        bt.insert(6);
        bt.insert(7);
		System.out.println("\n-------------------dfs-------------------");
        bt.preOrderPrint();
        System.out.println();
        bt.inOrderPrint();
        System.out.println();
        bt.postOrderPrint();
		System.out.println("\n-------------------bfs-------------------");
		bt.bfs();
    }
}

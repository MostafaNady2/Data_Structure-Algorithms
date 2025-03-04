public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> al = new ArrayList<>(5);

        al.insertAt(0, 10);
        al.insertAt(1, 20);
        al.insertAt(2, 30);

        for (int i = 0; i < al.size(); i++) {
            System.out.print(al.get(i) + " ");
        }

        System.out.println("\n------------------------------");
        System.out.println(al.get(6)); 
        System.out.println("------------------------------");

        al.removeAt(1);

        for (int i = 0; i < al.size(); i++) {
            System.out.print(al.get(i) + " ");
        }

        System.out.println();
        System.out.println("Size : " + al.size());
        System.out.println("Find 10 : " + al.find(10));

        al.clear();

        al.pushBack(1);
        al.pushBack(2);
        al.pushBack(3);
        al.pushBack(4);
        al.pushBack(5);

        System.out.println("\n------------------------------");
        for (int i = 0; i < al.size(); i++) {
            System.out.print(al.get(i) + " ");
        }
        System.out.println("\n------------------------------");

        al.pushBack(6);
        System.out.println("\n------------------------------");

        al.set(4, 50);

        for (int i = 0; i < al.size(); i++) {
            System.out.print(al.get(i) + " ");
        }
        System.out.println("\n------------------------------");
    }
}

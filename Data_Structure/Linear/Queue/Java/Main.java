public class Main {
    public static void main(String[] args) {
        Queue<Integer> q = new Queue<>();
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);

        q.print();
        System.out.println("Front: " + q.getFront());
        System.out.println("Back: " + q.getBack());
        System.out.println("Size: " + q.size());
        System.out.println("Find 3 : " + q.find(3));
        q.pop();
        System.out.println("--------------------------------");
        q.print();
        System.out.println("Front: " + q.getFront());
        System.out.println("Back: " + q.getBack());
        System.out.println("Size: " + q.size());
        System.out.println("----------------------------------");
        q.clear();
        System.out.println("Is empty: " + q.isEmpty());
        System.out.println("Size: " + q.size());

        System.out.println("----------------------------------");
        q.push(1);
        q.push(2);
        q.push(3);
        q.pop();
        q.pop();
        q.pop();
        q.print();
        q.push(1);
        q.push(2);
        q.print();
    }
    
}

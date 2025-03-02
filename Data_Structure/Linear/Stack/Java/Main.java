public class Main {
    public static void main(String[] args){
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        st.pop();
        st.print();
        System.out.println("Size: " + st.size());
        System.out.println("Is empty: " + st.isEmpty());
        System.out.println("Top: " + st.getTop());
    }
    
}

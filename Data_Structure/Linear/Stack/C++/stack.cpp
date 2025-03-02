#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
private:
    struct node
    {
        T val;
        node *next;
    };
    node *top;
    int count;

public:
    Stack()
    {
        top = NULL;
        count = 0;
    }
    void push(T val)
    {
        node *newVal = new node;
        newVal->val = val;
        newVal->next = top;
        top = newVal;
        count++;
    }
    void pop()
    {
        if (!isEmpty())
        {
            node *last = top;
            top = top->next;
            delete last;
            count--;
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    int size()
    {
        return count;
    }
    T getTop()
    {
        return top->val;
    }
    void print()
    {
        node *start = top;
        while (start != NULL)
        {
            cout << start->val << '\n';
            start = start->next;
        }
    }
    ~Stack() {
        while (!isEmpty())
        {
            pop();
        }
    };
};
int main()
{

    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    st.print();
    cout <<"Size : " <<st.size() << '\n';
    cout<<"Is empty : " << st.isEmpty() << '\n';
    cout <<"Top : " <<st.getTop() << '\n';

    return 0;
}
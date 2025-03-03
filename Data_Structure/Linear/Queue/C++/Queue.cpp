#include <bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{
private:
    struct node
    {
        T val;
        node *next;
    };
    node *front;
    node *back;
    int count;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
        count = 0;
    }
    void push(T val)
    {
        node *newVal = new node;
        newVal->val = val;
        newVal->next = NULL;
        if (back == NULL)
        {
            back = newVal;
            front = newVal;
        }
        else
        {
            back->next = newVal;
            back = newVal;
        }
        count++;
    }
    void pop()
    {
        if (!isEmpty())
        {
            node *last = front;
            if (front == back)
            {
                front = NULL;
                back = NULL;
            }
            else
            {
                front = front->next;
            }
            delete last;
            count--;
        }
    }
    bool isEmpty()
    {
        return count == 0;
    }
    T getfront()
    {
        if (!isEmpty())
        {
            return front->val;
        }
        else
        {
            throw runtime_error("the Queue is empty");
        }
    }
    T getback()
    {

        if (!isEmpty())
        {
            return back->val;
        }
        else
        {
            throw runtime_error("the Queue is empty");
        }
    }
    int size()
    {
        return count;
    }
    void print()
    {
        node *start = front;
        while (start != NULL)
        {
            cout << start->val << endl;
            start = start->next;
        }
    }
    void clear()
    {
        if (!isEmpty())
        {
            while (front != NULL)
            {
                node *last = front;
                front = front->next;
                delete last;
                count--;
            }
            front = back = NULL;
        }
    }
    int find(T val)
    {
        node *start = front;
        int index = 0;
        while (start != NULL)
        {
            if (start->val == val)
            {
                return index;
            }
            start = start->next;
            index++;
        }
        return -1;
    }
    ~Queue()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};
int main()
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.print();
    cout << "-----------------------------------\n";

    cout << "Front : " << q.getfront() << endl;
    cout << "Back : " << q.getback() << endl;
    cout << "Size : " << q.size() << endl;
    cout << "--------------------------------------\n";
    cout << "Find 3 : " << q.find(3) << endl;
    q.pop();
    cout << "-----------------------------------\n";
    q.print();

    cout << "Front : " << q.getfront() << endl;
    cout << "Back : " << q.getback() << endl;
    cout << "Size : " << q.size() << endl;

    q.clear();

    cout << "-----------------------------------\n";
    cout << "Is empty : " << q.isEmpty() << endl;
    cout << "Size : " << q.size() << endl;

    q.pop();

    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    
    cout << "-----------------------------------\n";
    q.push(1);
    q.push(2);
    q.print();

    return 0;
}
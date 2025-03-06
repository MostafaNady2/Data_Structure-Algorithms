#include <bits/stdc++.h>
using namespace std;
template <class T>
class LinkedList
{
private:
    struct Node
    {
        T val;
        Node *next;
    };
    Node *head;
    Node *tail;
    int count;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    void push_back(T val)
    {
        Node *newVal = new Node();
        newVal->val = val;
        newVal->next = nullptr;
        if (tail == nullptr)
        {
            head = newVal;
            tail = newVal;
        }
        else
        {
            tail->next = newVal;
            tail = newVal;
        }
        count++;
    }
    void push_front(T val)
    {
        Node *newVal = new Node();
        newVal->val = val;
        newVal->next = nullptr;
        if (head == nullptr)
        {
            head = newVal;
            tail = newVal;
        }
        else
        {
            newVal->next = head;
            head = newVal;
        }
        count++;
    }
    int size()
    {
        return count;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    bool contains(T val)
    {
        Node *start = head;
        while (start != nullptr)
        {
            if (start->val == val)
            {
                return true;
            }
            start = start->next;
        }
        return false;
    }
    void sort(bool ascending = true)
    {
        Node *first = head;
        Node *second = head;
        T temp;
        while (first != nullptr)
        {
            second = first->next;
            while (second != nullptr)
            {
                if (ascending)
                {
                    if (first->val > second->val)
                    {
                        temp = first->val;
                        first->val = second->val;
                        second->val = temp;
                    }
                }
                else
                {
                    if (first->val < second->val)
                    {
                        temp = first->val;
                        first->val = second->val;
                        second->val = temp;
                    }
                }
                second = second->next;
            }
            first = first->next;
        }
    }
    void pop_back()
    {
        if (count == 0)
        {
            return;
        }
        if (count == 1)
        {
            head = tail = nullptr;
            count = 0;
            return;
        }
        else
        {
            Node *start = head;
            while (start->next != tail)
            {
                start = start->next;
            }
            tail = start;
            Node *del = tail->next;
            tail->next = nullptr;
            delete del;
        }
        count--;
    }
    void pop_front(){
        if(count == 0){
            return;
        }
        if(count == 1){
            head = tail = nullptr;
            count = 0;
            return;
        }
        Node *del = head;
        head=head->next;
        del->next = nullptr;
        delete del;
        count--;
    }
    void print()
    {
        Node *start = head;
        cout << "[";
        while (start != nullptr)
        {
            cout << start->val << " ";
            start = start->next;
        }
        cout << "]\n";
    }
    void insertAt(int index,T val){
        if(index < 0 || index >= count){
            return;
        }
        if(index == 0){
            push_front(val);
            return;
        }
        if(index == count){
            push_back(val);
            return;
        }
        Node* start = head;
        index--;
        while (index--)
        {
            start = start->next;
        }
        Node *newVal = new Node;
        newVal->val = val;
        newVal->next = start->next;
        start->next = newVal;
        count++;
    }
    void deleteAt(int index){
        if(index < 0 || index >= count){
            return;
        }
        if(index == 0){
            pop_front();
            return;
        }
        if(index == count-1){
            pop_back();
            return;
        }
        index--;
        Node* start = head;
        while(index--){
            start = start->next;
        }
        Node *del = start->next;
        start->next = del->next;
        delete del;
        count--;
    }
    void clear(){
        Node *start = head;
        Node *temp;
        while (start != nullptr)
        {
            temp = start;
            start = start->next;
            delete temp;
        }
        count = 0;
        head = tail = nullptr;
    }
    ~LinkedList()
    {
        clear();
    }
};
int main()
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    cout << "After push_back: ";
    list.print();

    list.push_front(5);
    list.push_front(1);
    cout << "After push_front: ";
    list.print();

    cout << "Size: " << list.size() << endl;

    cout << "Is empty: " << (list.isEmpty() ? "true" : "false") << endl;

    cout << "Contains 10: " << (list.contains(10) ? "true" : "false") << endl;
    cout << "Contains 15: " << (list.contains(15) ? "true" : "false") << endl;

    list.sort(true);
    cout << "After ascending sort: ";
    list.print();

    list.sort(false);
    cout << "After descending sort: ";
    list.print();

    list.pop_back();
    cout << "After pop_back: ";
    list.print();

    list.pop_front();
    cout << "After pop_front: ";
    list.print();

    cout << "Inserting 25 at index 2: ";
    list.insertAt(2, 25);
    list.print();

    cout << "Inserting 50 at index 0: ";
    list.insertAt(0, 50);
    list.print();

    cout << "Inserting 5 at index " << list.size() << " (end of list): ";
    list.insertAt(list.size(), 5);
    list.print();

    cout << "Deleting element at index 2: ";
    list.deleteAt(2);
    list.print();

    cout << "Deleting element at index 0: ";
    list.deleteAt(0);
    list.print();

    cout << "Deleting last element: ";
    list.deleteAt(list.size() - 1);
    list.print();

    list.clear();
    cout << "After clear, isEmpty: " << (list.isEmpty() ? "true" : "false") << endl;

    return 0;
}


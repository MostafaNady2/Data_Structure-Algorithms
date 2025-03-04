#include <bits/stdc++.h>
using namespace std;
template <class T>
class ArrayList
{
private:
    T *arr;
    int maxSize;
    int actualSize;

public:
    ArrayList(int size)
    {
        if (size > 0)
        {
            maxSize = size;
            actualSize = 0;
            arr = new T[maxSize];
        }
        else
        {
            cout << "Error: Invalid size\n";
            maxSize = actualSize = 0;
            arr = nullptr;
        }
    }
    void insertAt(int index, T val)
    {
        if (index < 0 || index >= maxSize)
        {
            cout << "Error: index out of range\n";
        }
        else if (isFull())
        {
            cout << "Error: Array is full\n";
        }
        else
        {
            for (int i = actualSize; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = val;
            actualSize++;
        }
    }
    bool isFull()
    {
        return actualSize == maxSize;
    }
    void removeAt(int index)
    {
        if (index < 0 || index >= actualSize)
        {
            cout << "index out of range\n";
        }
        else if (isEmpty())
        {
            cout << "ArrayList is Empty";
        }
        else
        {
            for (int i = index; i < actualSize - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[actualSize - 1] = T();
            actualSize--;
        }
    }
    T get(int index)
    {
        if (index < 0 || index >= actualSize)
        {
            cout << "index out of range\n";
            return T();
        }
        return arr[index];
    }
    bool isEmpty()
    {
        return actualSize == 0;
    }
    void clear()
    {
        delete[] arr;
        actualSize = 0;
        // arr = new T[maxSize];
    }
    int size()
    {
        return actualSize;
    }
    int find(T val)
    {
        for (int i = 0; i < actualSize; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    void push_back(T val)
    {
        if (!isFull())
        {
            arr[actualSize] = val;
            actualSize++;
        }
        else
        {
            cout << "Array is full";
        }
    }
    void set(int index, T val)
    {
        if (index < 0 || index >= actualSize)
        {
            cout << "Invalid index";
        }
        else
        {
            arr[index] = val;
        }
    }
    ~ArrayList()
    {
        delete[] arr;
    }
};

int main()
{
    ArrayList<int> al(5);
    al.insertAt(0, 10);
    al.insertAt(1, 20);
    al.insertAt(2, 30);
    for (int i = 0; i < al.size(); i++)
    {
        cout << al.get(i) << " ";
    }
    cout << "\n------------------------------\n";
    cout << al.get(6);
    cout << "\n------------------------------\n";
    al.removeAt(1);
    for (int i = 0; i < al.size(); i++)
    {
        cout << al.get(i) << " ";
    }
    cout << '\n';
    cout << "Size : " << al.size() << '\n';
    cout << "Find 10 : " << al.find(10);
    cout << '\n';
    al.clear();
    al.push_back(1);
    al.push_back(2);
    al.push_back(3);
    al.push_back(4);
    al.push_back(5);
    cout << "\n------------------------------\n";
    for (int i = 0; i < al.size(); i++)
    {
        cout << al.get(i) << " ";
    }
    cout << "\n------------------------------\n";
    al.push_back(6);
    cout << "\n------------------------------\n";
    al.set(4, 50);
    for (int i = 0; i < al.size(); i++)
    {
        cout << al.get(i) << " ";
    }
    cout << "\n------------------------------\n";

    return 0;
}
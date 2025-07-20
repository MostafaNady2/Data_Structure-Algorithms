#include <bits/stdc++.h>
using namespace std;
template <class T>
class BinarySearchTree
{
private:
	struct Node
	{
		T val;
		Node *left;
		Node *right;
		Node(T val)
		{
			this->val = val;
			left = nullptr;
			right = nullptr;
		}
	};
	Node *root;
	Node *getMin(Node *base)
	{
		Node *curr = base;
		while (curr->left != nullptr)
		{
			curr = curr->left;
		}
		return curr;
	}
	Node *getMax(Node *base)
	{
		Node *curr = base;
		while (curr->right != nullptr)
		{
			curr = curr->right;
		}
		return curr;
	}
	void printTree(Node *node){
		if(node == nullptr){
			return;
		}
		printTree(node->left);
		cout<<node->val<<" ";
		printTree(node->right);
	}
	void deleteTree(Node *node)
	{
		if (node == nullptr)
		{
			return;
		}
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
		node = nullptr;
	}
public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	void insert(T val)
	{
		Node *node = new Node(val);
		if (root == nullptr)
		{
			root = node;
			return;
		}
		Node *curr = root;
		Node *parent = curr;
		while (curr != nullptr)
		{
			parent = curr;
			if (val > curr->val)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}
		if (val > parent->val)
		{
			parent->right = node;
		}
		else
		{
			parent->left = node;
		}
	}
	bool find(T val)
	{
		Node *curr = root;
		while (curr != nullptr)
		{
			if (val > curr->val)
			{
				curr = curr->right;
			}
			else if (val < curr->val)
			{
				curr = curr->left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	T getMinVal(){
		return getMin(root)->val;
	}
	T getMaxVal(){
		return getMax(root)->val;
	}
	bool remove(Node *&node, T val)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (val > node->val)
		{
			return remove(node->right, val);
		}
		else if (val < node->val)
		{
			return remove(node->left, val);
		}
		else
		{
			if (!node->left && !node->right)
			{
				delete node;
				node = nullptr;
			}
			else if (node->left && node->right)
			{
				node->val = getMin(node->right)->val;
				remove(node->right, node->val);
			}
			else if (node->left || node->right)
			{
				if (node->left)
				{
					Node *t = node;
					node = node->left;
					delete t;
				}
				else
				{
					Node *t = node;
					node = node->right;
					delete t;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}
	bool remove(T val)
	{
		return remove(root, val);
	}

	void clear(){
		deleteTree(root);
		root = nullptr;
	}

	void print(){
		if(!isEmpty()){
			printTree(root);
		}
	}
	bool isEmpty(){
		return root == nullptr;
	}
	~BinarySearchTree()
	{
		clear();
	}
};
int main()
{
	BinarySearchTree<int> bst;

	cout << "\nInserting values: 5, 3, 7, 2, 4, 6, 8 \n";
	bst.insert(5);
	bst.insert(3);
	bst.insert(7);
	bst.insert(2);
	bst.insert(4);
	bst.insert(6);
	bst.insert(8);

	cout << "Initial Tree (in-order): ";
	bst.print();
	cout << "\n";

	cout << "\n----- Removing 3 (node with one child) -----\n";
	bst.remove(3);
	cout << "Tree after removing 3: ";
	bst.print();
	cout << "\n";

	cout << "\n----- Removing 5 (node with two children) -----\n";
	bst.remove(5);
	cout << "Tree after removing 5: ";
	bst.print();
	cout << "\n";

	cout << "\n----- Removing 7 (node with one child) -----\n";
	bst.remove(7);
	cout << "Tree after removing 7: ";
	bst.print();
	cout << "\n";

	cout << "\nInserting values: 3, 5, 10\n";
	bst.insert(3);
	bst.insert(5);
	bst.insert(10);

	cout << "Tree after re-inserting 3, 5, 10: ";
	bst.print();
	cout << "\n";

	cout << "\ngetMin / getMax after re-insertions\n";

	cout << "Minimum value: " << bst.getMinVal() << "\n";
	cout << "Maximum value: " << bst.getMaxVal() << "\n";

	cout << "\ntest find a value\n";

	cout << "Find 3: " << (bst.find(3) ? "true" : "false") << "\n";
	cout << "Find 6: " << (bst.find(6) ? "true" : "false") << "\n";
	cout << "Find 9: " << (bst.find(9) ? "true" : "false")<< "\n";

	cout<<"------------- test clear tree -------------\n";
	bst.clear();
	cout<<"Tree after clear: ";
	bst.print();
    cout<<"\ntree is empty: "<<(bst.isEmpty()?"true":"false");
	return 0;
}

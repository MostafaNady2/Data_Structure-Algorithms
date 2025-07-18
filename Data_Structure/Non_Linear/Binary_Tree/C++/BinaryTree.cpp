#include <bits/stdc++.h>
using namespace std;
template <class T>
class BinaryTree
{
private:
    struct Node
    {
        T val;
        Node *left = NULL;
        Node *right = NULL;
        Node(T val)
        {
            this->val = val;
        }
    };
	Node *root;
	public:
    BinaryTree() {         // empty constructor
		root = NULL;
	}; 
    void insert(T val)
    {
        Node *node = new Node(val);
        if (root == NULL)
        {
            root = node;
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left == NULL)
            {
                temp->left = node;
                return;
            }
            else
            {
                q.push(temp->left);
            }
            if (temp->right == NULL)
            {
                temp->right = node;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
    void preOrderPrint(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->val << " ";
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
    void inOrderPrint(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inOrderPrint(node->left);
        cout << node->val << " ";
        inOrderPrint(node->right);
    }
    void postOrderPrint(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        cout << node->val << " ";
    }
    void preOrderPrint()
    {
        preOrderPrint(root);
    }
    void inOrderPrint()
    {
        inOrderPrint(root);
    }
    void postOrderPrint()
    {
        postOrderPrint(root);
    }
    void deleteTree(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    void BFS(Node* node){
        if(node == NULL){
            return;
        }
		queue<Node*> q;
		q.push(node);
		while (!q.empty())
		{
			Node* curr = q.front();

			if(curr->left != NULL){
				q.push(curr->left);
			}

			if(curr->right != NULL){
				q.push(curr->right);
			}
			
			cout<<curr->val<<" ";
			q.pop();
		}
    }
	void bfs(){
		BFS(root);
	}
    ~BinaryTree()
    {
        deleteTree(root);
    }
};
int main()
{
    
    BinaryTree<int> bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
	cout<<"\n----------------------dfs------------------------\n";
    bt.preOrderPrint();
    cout << endl;
    bt.inOrderPrint();
    cout << endl;
    bt.postOrderPrint();
	cout<<"\n----------------------bfs------------------------\n";
	bt.bfs();
    
    return 0;
}



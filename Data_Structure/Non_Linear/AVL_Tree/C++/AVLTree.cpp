#include <bits/stdc++.h>
using namespace std;
template <class T> 
class AVLTree{
private:
	struct Node{
		T val;
		Node *left;
		Node *right;
		int height;
		Node(T val){
			this->val = val;
			left = right = nullptr;
			height = 1;
		}
	};
	Node *root;

	int height(Node* node){
		if(node == nullptr){
			return 0;
		}
		return node->height;
	}
	int balanceFactor(Node* node){
		if(node == nullptr){
			return 0;
		}
		return height(node->left) - height(node->right);
	}
	Node* insert(Node* node , T val){
		if(node == nullptr){
			return new Node(val);
		}
		if(val > node->val){
			node->right = insert(node->right , val);
		}
		else if(val < node->val){
			node->left = insert(node->left , val);
		}

		node->height = max(height(node->left) , height(node->right)) + 1; // update height

		int bf = balanceFactor(node);  // balance factor

		if(bf > 1 && val < node->left->val){  // left left
			node = rightRotate(node);
		}
		if(bf < -1 && val > node->right->val){  // right right
			node = leftRotate(node);
		}
		if(bf > 1 && val > node->left->val){  // left right
			node->left = leftRotate(node->left);
			node = rightRotate(node);
		}
		if(bf < -1 && val < node->right->val){  // right left
			node->right = rightRotate(node->right);
			node = leftRotate(node);
		}
		return node;
	}
	Node* rightRotate(Node* node){
		Node* mid = node->left;
		Node* right = mid->right;

		mid->right = node;
		node->left = right;

		node->height = max(height(node->left) , height(node->right)) + 1;
		mid->height = max(height(mid->left) , height(mid->right)) + 1;

		return mid;
	}
	Node* leftRotate(Node* node){
		Node* mid = node->right;
		Node* left = mid->left;

		mid->left = node;
		node->right = left;

		node->height = max(height(node->left) , height(node->right)) + 1;
		mid->height = max(height(mid->left) , height(mid->right)) + 1;

		return mid;
	}
	void printTree(Node* base){
		if(base == nullptr){
			return;
		}
		printTree(base->left);
		cout<<base->val<<" ";
		printTree(base->right);
	}
	Node* getMin(Node* base){
		Node* curr = base;
		while(curr->left != nullptr){
			curr = curr->left;
		}
		return curr;
	}
	Node* getMax(Node* base){
		Node* curr = base;
		while(curr->right != nullptr){
			curr = curr->right;
		}
		return curr;
	}
	Node* remove(Node* node,T val){
		if(node == nullptr){
			return nullptr;
		}
		if(val > node->val){
			node->right = remove(node->right , val);
		}else if(val < node->val){
			node->left = remove(node->left ,val);
		}else{
			if(!node->left && !node->right){ // leaf node
				return nullptr;
			}else if(node->left && node->right){  // two children
				Node* min = getMin(node->right);
				node->val = min->val;
				node->right = remove(node->right,node->val);
			}else{                        // one child
				if(node->right){
					Node* t = node;
					node = node->right;
					delete t;
					t = nullptr;
				}else{
					Node* t = node;
					node = node->left;
					delete t;
					t = nullptr;
				}
			}
		}
		node->height = max(height(node->left) , height(node->right)) + 1;   // update height

		int bf = balanceFactor(node);  // balance factor

		if(bf > 1 && balanceFactor(node->left) >= 0){  // left left
			node = rightRotate(node);
		}
		if(bf < -1 && balanceFactor(node->right) <= 0){  // right right
			node = leftRotate(node);
		}
		if(bf > 1 && balanceFactor(node->left) < 0){  // left right
			node->left = leftRotate(node->left);
			node = rightRotate(node);
		}
		if(bf < -1 && balanceFactor(node->right) > 0){  // right left
			node->right = rightRotate(node->right);
			node = leftRotate(node);
		}
		return node;
	}
	void deleteTree(Node* base){
		if(base == nullptr){
			return;
		}
		deleteTree(base->left);
		deleteTree(base->right);
		delete base;
		base = nullptr;
	}
public:
	AVLTree(){
		root = nullptr;
	}
	void insert(T val){
		root = insert(root , val);
	}
	bool remove(T val){
		if(!find(val)){
			return false;
		}
		root = remove(root,val);
		return true;
	}
	void print(){
		printTree(root);
	}
	bool find(T val){
		Node* curr = root;
		while(curr != nullptr){
			if(val > curr->val){
				curr = curr->right;
			}else if(val < curr->val){
				curr = curr->left;
			}else{
				return true;
			}
		}
		return false;
	}
	bool isEmpty(){
		return root == nullptr;
	}
	T getMinVal(){
		return getMin(root)->val;
	}
	T getMaxVal(){
		return getMax(root)->val;
	}
	void clear(){
		if(root == nullptr){
			return;
		}
		deleteTree(root);
		root = nullptr;
	}

};
int main(){
	AVLTree<int> bst;
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
#include<bits/stdc++.h>
using namespace std;
class HuffmanCoding{
private:
	struct Node{
		char c;
		int count;
		Node* left;
		Node* right;
		Node(char c , int count) : c(c),count(count) , left(nullptr) ,right(nullptr){}; 
	};
	struct Compare{
		bool operator()(Node* a , Node* b){
			return a->count > b->count;
		}
	};
	void storeCode(Node* node , string s){
		if(node->left == nullptr && node->right == nullptr){
			codes[node->c] = s;
			return;
		}
		storeCode(node->left , s + '0');
		storeCode(node->right , s + '1');
	}
	void store(string s){
		this->s = s;
		map<char,int> m;
		for(char c : s){
			m[c]++;
		}
		priority_queue<Node* , vector<Node*> , Compare> pq;
		for(auto it : m){
			pq.push(new Node(it.first , it.second));
		}
		while(pq.size() > 1){
			Node* a = pq.top();
			pq.pop();
			Node* b = pq.top();
			pq.pop();
			Node* c = new Node('\0' , a->count + b->count);
			c->left = a;
			c->right = b;
			pq.push(c);
		}
		this->root = pq.top();
	}
	Node* root;
	string s;
	unordered_map<char,string> codes;
public:
	
	void encode(string str){
		store(str);
		storeCode(root , "");
	}
    void compressionStats(){
		cout<<"string before compression : "<<s.size() * 8<<" bit\n";
		int total = 0;
		map<char,int> f;
		for(char c : s){
			f[c]++;
		}
		for(auto it : codes){
			total += it.second.size()*f[it.first];
		}
		cout<<"string after compression : "<<total<<" bit ," << "table size : "<<codes.size() * 8<<" bit\n";
		cout<<"total : "<<total + codes.size() * 8<<" bit\n";
		cout<<"compression ratio : "<<(double)(s.size() * 8) / (total + codes.size() * 8)<<"\n";
	}
	void printCodes(){
		cout<<"-------- codes --------\n";
		for(auto p : codes){
			cout<<p.first<<" : "<<p.second<<"\n";
		}
		cout<<"----------------\n";
	}
};
int main(){
	string s = "mjhcdibygwfwejifwiue jugcfbcwewiy fvvwevhwihi";
	// cin>>s;
	HuffmanCoding hc;
	hc.encode(s);
	hc.compressionStats();
	hc.printCodes();

	return 0;
}
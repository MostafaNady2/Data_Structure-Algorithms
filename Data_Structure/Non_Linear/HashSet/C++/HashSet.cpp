#include <bits/stdc++.h>
using namespace std;
template <typename k>
class HashSet{
private:
	vector<vector<k>> vec;
	int length;
	int count;
public:
	HashSet(){
		this->length = 16;
		vec.resize(this->length);
		this->count = 0;
	}

	size_t hashCode(k key){
		hash<k> h;
		return h(key);
	}
	void put(k key){
		int index = (int)hashCode(key) % this->length;
		int l = vec[index].size();
		for(int i = 0 ; i < l ; i++){
			if(vec[index][i] == key){
				return;
			}
		}
		vec[index].emplace_back(key);
		this->count++;
	}
	k get(k key){
		int index = (int)hashCode(key) % this->length;
		for(auto a : vec[index]){
			if(a == key){
				return a;
			}
		}
		return -1;
	}
	bool remove(k key){
		int index = (int)(hashCode(key)) % this->length;
		int l = vec[index].size();
		for(int i = 0 ; i < l ;i++){
			if(vec[index][i] == key){
				int j = i;
				while(j < l-1){
					vec[index][j]=vec[index][j+1];
				}
				vec[index].pop_back();
				this->count--;
				return true;
			}
		}
		return false;
	}
	int size(){
		return this->count;
	}
	bool isEmpty(){
		return this->count == 0;
	}
	void clear(){
		vec.clear();
		vec.resize(this->length);
		this->count = 0;
	}

};
int main(){
	HashSet<int> set;
	set.put(1);
	set.put(2);
	set.put(3);
	set.put(4);
	cout<<"----------------- testing get ----------------- \n";
	cout<<"get 1 : "<<set.get(1)<<endl;
	cout<<"get 2 : "<<set.get(2)<<endl;
	cout<<"get 3 : "<<set.get(3)<<endl;
	cout<<"get 8 (not in set): "<<set.get(8)<<endl;

	cout<<"----------------- testing remove -----------------\n";
	cout<<"size : "<<set.size()<<endl;
	set.remove(1);
	cout<<"size after removing 1 : "<<set.size()<<endl;

	cout<<"----------------- testing get deleted key -----------------\n";
	cout<<"get 1 (deleted) : "<<set.get(1)<<endl;

	cout<<"----------------- testing isEmpty -----------------\n";
	cout<<"is empty : "<<(set.isEmpty() ? "true": "false")<<endl;

	cout<<"----------------- testing clear -----------------\n";
	set.clear();
	cout<<"is empty : "<<(set.isEmpty() ? "true": "false")<<endl;

	return 0;
}
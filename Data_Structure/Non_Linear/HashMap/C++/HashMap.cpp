#include <bits/stdc++.h>
using namespace std;
template <typename k,typename v>
class HashMap{
private:
	vector<vector<pair<k,v>>> vec;
	int length;
	int count;
public:
	HashMap(){
		this->length = 16;
		vec.resize(this->length);
		this->count = 0;
	}

	size_t hashCode(k key){
		hash<k> h;
		return h(key);
	}
	void put(k key,v val){
		int index = (int)hashCode(key) % this->length;
		int l = vec[index].size();
		for(int i = 0 ; i < l ; i++){
			if(vec[index][i].first == key){
				vec[index][i].second = val;
				return;
			}
		}
		vec[index].emplace_back(key,val);
		this->count++;
	}
	v get(k key){
		int index = (int)hashCode(key) % this->length;
		for(auto a : vec[index]){
			if(a.first == key){
				return a.second;
			}
		}
		return "not found";
	}
	bool remove(k key){
		int index = (int)(hashCode(key)) % this->length;
		int l = vec[index].size();
		for(int i = 0 ; i < l ;i++){
			if(vec[index][i].first == key){
				int j = i;
				while(j < l-1){
					vec[index][j].first=vec[index][j+1].first;
					vec[index][j].second=vec[index][j+1].second;
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
	HashMap<int,string> map;
	map.put(1,"abc");
	map.put(2,"def");
	map.put(3,"ghi");
	map.put(4,"jkl");
	map.put(5,"mno");
	cout<<"----------------- testing get ----------------- \n";
	cout<<"get 1 : "<<map.get(1)<<endl;
	cout<<"get 2 : "<<map.get(2)<<endl;
	cout<<"get 3 : "<<map.get(3)<<endl;
	cout<<"get 8 (not in map): "<<map.get(8)<<endl;

	cout<<"----------------- testing remove -----------------\n";
	cout<<"size : "<<map.size()<<endl;
	map.remove(1);
	cout<<"size after removing 1 : "<<map.size()<<endl;

	cout<<"----------------- testing get deleted key -----------------\n";
	cout<<"get 1 (deleted) : "<<map.get(1)<<endl;


	cout<<"----------------- testing isEmpty -----------------\n";
	cout<<"is empty : "<<(map.isEmpty() ? "true": "false")<<endl;

	cout<<"----------------- testing clear -----------------\n";
	map.clear();
	cout<<"is empty : "<<(map.isEmpty() ? "true": "false")<<endl;

	return 0;
}
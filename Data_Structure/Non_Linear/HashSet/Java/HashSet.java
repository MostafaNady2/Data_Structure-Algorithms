import java.util.*;
class HashSet <k>{
	private int count;
	private int length;
	private List<ArrayList<k>> vec;
	
	private int hashCode(k key){
		return key.hashCode();
	}
	public HashSet(){
		this.length = 16;
		vec = new ArrayList<>();
		for(int i = 0 ; i < this.length ; i++){
			vec.add(new ArrayList<k>());
		}
		this.count = 0;
	}
	public void put(k key){
		int index = (int)hashCode(key) % this.length;
		int l = vec.get(index).size();
		for(int i = 0 ; i < l ;i++){
			if(vec.get(index).get(i) == key){
				return;
			}
		}
		vec.get(index).add(key);
		this.count++;
	}
	public k get(k key){
		int index = (int)hashCode(key) % this.length;
		for(k a : vec.get(index)){
			if(hashCode(a) == hashCode(key)){
				return a;
			}
		}
		return null;
	}
	public boolean remove(k key){
		int index = (int)(hashCode(key)) % this.length;
		int l = vec.get(index).size();
		for(int i = 0 ; i < l ; i++){
			if(vec.get(index).get(i) == key){
				vec.get(index).remove(i);
				this.count--;
				return true;
			}
		}
		return false;
	}
	public boolean isEmpty() {
		return count == 0;
	}
	public int size() {
		return count;
	}
	public void clear() {
		vec = new ArrayList<>();
		for(int i = 0 ; i < this.length ; i++){
			vec.add(new ArrayList<k>());
		}
		this.count = 0;
	}
	
}
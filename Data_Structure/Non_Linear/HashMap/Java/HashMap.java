import java.util.*;
class HashMap <k,v>{
	private int count;
	private int length;
	private List<ArrayList<Pair<k,v>>> vec;
	
	private int hashCode(k key){
		return key.hashCode();
	}
	public HashMap(){
		this.length = 16;
		vec = new ArrayList<>();
		for(int i = 0 ; i < this.length ; i++){
			vec.add(new ArrayList<Pair<k,v>>());
		}
		this.count = 0;
	}
	public void put(k key,v val){
		int index = (int)hashCode(key) % this.length;
		int l = vec.get(index).size();
		for(int i = 0 ; i < l ;i++){
			if(vec.get(index).get(i).key == key){
				vec.get(index).get(i).value = val;
				return;
			}
		}
		vec.get(index).add(new Pair<k,v>(key,val));
		this.count++;
	}
	public v get(k key){
		int index = (int)hashCode(key) % this.length;
		for(Pair<k,v> a : vec.get(index)){
			if(hashCode(a.key) == hashCode(key)){
				return a.value;
			}
		}
		return null;
	}
	public boolean remove(k key){
		int index = (int)(hashCode(key)) % this.length;
		int l = vec.get(index).size();
		for(int i = 0 ; i < l ; i++){
			if(vec.get(index).get(i).key == key){
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
			vec.add(new ArrayList<Pair<k,v>>());
		}
		this.count = 0;
	}
	
}
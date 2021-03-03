#define N 1000007
class MyHashMap {
    vector<int> vec;
public:
    
    /** Initialize your data structure here. */
    MyHashMap() {
        vec.assign(N, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        vec[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return vec[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vec[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
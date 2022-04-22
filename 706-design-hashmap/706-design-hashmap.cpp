class MyHashMap {
public:
    vector<int> buffer;
    MyHashMap() {
        buffer.resize(1000001,-1);
        cout<<"const";
    }
    
    void put(int key, int value) {
        buffer[key]=value;
    }
    
    int get(int key) {
        return buffer[key];
    }
    
    void remove(int key) {
        buffer[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
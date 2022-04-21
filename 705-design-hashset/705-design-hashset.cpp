class MyHashSet {
public:
    set<int> buffer;
    MyHashSet() {
        
        cout<<"const"<<endl;
    }
    
    void add(int key) {
        buffer.insert(key);
    }
    
    void remove(int key) {
        buffer.erase(key);
    }
    
    bool contains(int key) {
        return buffer.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
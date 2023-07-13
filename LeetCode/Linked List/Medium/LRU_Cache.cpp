class LRUCache {
public:
    int size;
    
    list<int> recent;
    unordered_map<int,list<int>::iterator> key_node;
    unordered_map<int,int> key_val; 
    
    LRUCache(int capacity):  size(capacity) {}
    
    int get(int key) {
        if(key_val.find(key) == key_val.end())
            return -1;
        
        update(key); // added at front 
        return key_val[key];
    }
    
    void put(int key, int value) {
        // if new entry and key_val.size() == capacity 
        if(key_val.size() == size && key_val.find(key) == key_val.end())
            evict();
        
        update(key);
        key_val[key] = value;
    }
  
    void update(int key){
        if(key_val.find(key) != key_val.end()) // if present in the list 
            recent.erase(key_node[key]);
        
        recent.push_front(key);
        key_node[key] = recent.begin();
    }
  
    void evict(){ // remove the lru element 
        key_node.erase(recent.back());
        key_val.erase(recent.back());
        recent.pop_back();       
    }
};

class LRUCache {
    int capacity;
    
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
    };
    
    unordered_map<int, node*> mp;
    node* head;
    node* tail;
    
    void removeNode(node* t){
        node* prev = t->prev;
        node* next = t->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void addNode(node* t){
        t->prev = head;
        t->next = head->next;
        
        head->next->prev = t;
        head->next = t;
    }
    
    void moveNode(node* t){
        removeNode(t);
        addNode(t);
    }
    
    node* popTail(){
        node* last = tail->prev;
        removeNode(last);
        return last;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new node();
        tail = new node();
        
        head->next = tail;
        head->prev = NULL;
        
        tail->next = NULL;
        tail->prev = head;
    }
    
    
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        node* t = mp[key];
        moveNode(t);
        return t->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            // already available
            node* t = mp[key];
            t->val = value;
            moveNode(t);
        }else{
            node* t = new node();
            t->key = key;
            t->val = value;
            
            addNode(t);
            mp[key] = t;
            
            if(mp.size() > capacity){
                node* last = popTail();
                mp.erase(last->key);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

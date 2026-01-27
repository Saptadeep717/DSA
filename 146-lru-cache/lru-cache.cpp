class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node *prev, *next;
        
        Node(int k, int v){
            key = k;
            val = v;
            prev=next=NULL;
        }
    };
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*>mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode-> next = temp;
        temp->prev = newNode;
        newNode->prev=head;
        head->next=newNode;
    }
    
    void deleteNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* existingNode = mp[key];
            int res = existingNode->val;
            mp.erase(key);
            deleteNode(existingNode);
            addNode(existingNode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        else if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
         Node* nNode = new Node(key,value);
         addNode(nNode);
         mp[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
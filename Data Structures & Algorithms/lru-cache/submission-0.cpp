class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;

        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node* newnode) {
        Node* temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    void delnode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* resnode = mpp[key];

        // Remove from current position
        delnode(resnode);

        // Move to front (most recently used)
        addnode(resnode);

        return resnode->val;
    }

    void put(int key, int value) {

        // Key already exists
        if(mpp.find(key) != mpp.end()) {
            Node* existingnode = mpp[key];

            mpp.erase(key);
            delnode(existingnode);
            delete existingnode;
        }

        // Capacity full
        if(mpp.size() == cap) {
            Node* lru = tail->prev;

            mpp.erase(lru->key);
            delnode(lru);
            delete lru;
        }

        // Add new node at front
        Node* newnode = new Node(key, value);

        addnode(newnode);
        mpp[key] = newnode;
    }
};
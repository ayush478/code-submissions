class LRUCache {
    class Node {
       public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    void insertAfterHead(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
    }

    void deleteNode(Node* node) {
        Node* nnext = node->next;
        Node* pprev = node->prev;
        nnext->prev = pprev;
        pprev->next = nnext;
    }

   public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            node->val = value;
            insertAfterHead(node);
            return;
        }
        if (cap == mp.size()) {
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete (lru);
        }
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insertAfterHead(newNode);
    }
};

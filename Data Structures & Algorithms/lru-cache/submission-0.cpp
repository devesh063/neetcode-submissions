class Node
{
public:
    int key;
    int value;
    
    Node *next;
    Node *prev;

    Node(int _key, int _value) : key(_key), value(_value), next(nullptr), prev(nullptr)
    { 
    }
};
class LRUCache {
public:

    int cap;
    unordered_map<int,Node*> map;
    Node *head, *tail;
    LRUCache(int capacity) : cap(capacity) 
    {
           head = new Node(-1,-1);
           tail = new Node(-1,-1);

           head->next = tail;
           tail->prev = head;
    }
    
    int get(int key) 
    {
        if(map.find(key) == map.end())
          return -1;
        
        Node *node = map[key];
        
        deleteNode(node);

        insertNode(node);

        return node->value;
    }
    
    void deleteNode(Node *node)
    {
       node->prev->next = node->next;
       node->next->prev = node->prev;
    }
    
    void insertNode(Node *node)
    {
        tail->prev->next = node;
        node->prev = tail->prev;

        node->next = tail;
        tail->prev = node;        
    }

    void put(int key, int value) 
    {
        if(map.find(key) != map.end())
        {
            Node *node = map[key];

            if(node->value != value)
              node->value = value;

            deleteNode(node);
            
            insertNode(node);
        }    
        else
        {
            if(map.size() == cap)
            {
                Node *lru = head->next;

                deleteNode(lru);

                map.erase(lru->key);

                delete lru;
            }

            Node *newNode = new Node(key,value);

            insertNode(newNode);

            map[key] = newNode;
        }
    }
};

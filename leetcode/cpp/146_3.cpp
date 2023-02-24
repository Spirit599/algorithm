namespace jiangxy
{
    template <typename dataType>
    class ListNode
    {
    public:
        ListNode* prev;
        ListNode* next;
        dataType data_;
        ListNode()
            :   prev(nullptr),
                next(nullptr)
        {}
        ListNode(dataType data)
            :   prev(nullptr),
                next(nullptr),
                data_(data)
        {}
    };

    // typedef ListNode* ListNodePtr;

    template <typename dataType>
    class list
    {
    private:
        typedef ListNode<dataType> ListNode;
        ListNode head;
        ListNode* phead;
        int size_;
    public:
        list()
        {
            size_ = 0;
            phead = &head;
            phead->next = phead;
            phead->prev = phead;
        }

        void push_back(dataType data)
        {
            ListNode* newData = new ListNode(data);
            newData->next = phead;
            newData->prev =  phead->prev;
            phead->prev->next = newData;
            phead->prev = newData;
            ++size_;
        }

        void push_front(dataType data)
        {
            ListNode* newData = new ListNode(data);
            newData->prev = phead;
            newData->next = phead->next;
            phead->next->prev = newData;
            phead->next = newData;
            ++size_;
        }

        void pop_back()
        {
            phead->prev = phead->prev->prev;
            phead->prev->next = phead;
            --size_;
        }

        void pop_front()
        {
            phead->next = phead->next->next;
            phead->next->prev = phead;
            --size_;
        }

        int size() const
        {
            return size_;
        }

        void moveToFront(ListNode* p)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;

            p->prev = phead;
            p->next = phead->next;
            phead->next->prev = p;
            phead->next = p;
        }

        dataType front()
        {
            return phead->next->data_;
        }

        dataType back()
        {
            return phead->prev->data_;
        }

        ListNode* begin()
        {
            return phead->next; 
        }
    };
}

typedef pair<int, int> pii;

class LRUCache {
public:
    unordered_map<int, jiangxy::ListNode<pii>*> _table;
    jiangxy::list<pii> _list;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {

        auto it = _table.find(key);
        if(it == _table.end())
            return -1;
        // _list.splice(_list.begin(), _list, it->second);
        _list.moveToFront(it->second);
        return _list.front().second;
    }
    
    void put(int key, int value) {

        auto it = _table.find(key);
        if(it == _table.end())
        {
            _list.push_front(make_pair(key, value));
            _table[key] = _list.begin();
            if(_list.size() > capacity)
            {
                int rmKey = _list.back().first;
                _list.pop_back();
                _table.erase(rmKey);
            }
        }
        else
        {
            it->second->data_.second = value;
            _list.moveToFront(it->second);
            // _list.splice(_list.begin(), _list, it->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
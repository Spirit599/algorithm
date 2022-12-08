class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> _table;
    list<pair<int, int>> _list;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {

        auto it = _table.find(key);
        if(it == _table.end())
            return -1;
        _list.splice(_list.begin(), _list, it->second);
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
            it->second->second = value;
            _list.splice(_list.begin(), _list, it->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
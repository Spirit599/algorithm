class LRUCache {
public:
    list<pair<int, int>> _list;
    unordered_map<int, list<pair<int, int>>::iterator> _table;
    int _capacity;
    LRUCache(int capacity) : _capacity(capacity)
    {
    }
    
    int get(int key) {

        auto it = _table.find(key);
        if(it != _table.end())
        {
            _list.splice(_list.begin(), _list, it->second);
            return _list.front().second;
        }
        return -1;
    }
    
    void put(int key, int value) {

        auto it = _table.find(key);
        if(it != _table.end())
        {
            it->second->second = value;
            _list.splice(_list.begin(), _list, it->second);
        }
        else
        {
            _list.push_front({key, value});
            _table[key] = _list.begin();
            if(_list.size() == _capacity + 1)
            {
                _table.erase(_list.back().first);
                _list.pop_back();
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
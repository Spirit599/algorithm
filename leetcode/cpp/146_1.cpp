//LRU
//hash list

class LRUCache {
private:
    int _capacity;
    unordered_map<int, list<pair<int, int>>::iterator> _table;
    list<pair<int, int>> _lru;
public:
    LRUCache(int capacity) : _capacity(capacity)
    {

    }
    
    int get(int key) {

        if(_table.count(key) != 1)
            return -1;
        //pair<int, int> key_value = *_table[key];
        //_lru.erase(_table[key]);
        //_lru.push_front(key_value);
        _lru.splice(_lru.begin(), _lru, _table[key]);
        //_table[key] = _lru.begin();
        return _lru.front().second;
    }
    
    void put(int key, int value) {
        if(_table.count(key) != 1)
        {
            if(_lru.size() == _capacity)
            {
                _table.erase(_lru.back().first);
                _lru.pop_back();
            }
            _lru.push_front({key, value});
            _table[key] = _lru.begin();
        }
        else
        {
            //_lru.erase(_table[key]);
            _lru.splice(_lru.begin(), _lru, _table[key]);
            _lru.front().second = value;
            //_table[key] = _lru.begin();
        }
        // _lru.push_front({key, value});
        // _table[key] = _lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
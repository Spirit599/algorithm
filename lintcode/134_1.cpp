//134 · LRU缓存策略
#include <list>
class LRUCache {
public:
    /*
    * @param capacity: An integer
    */
    std::unordered_map<int, list<pair<int, int>>::iterator> _table;
    std::list<pair<int, int>> _lru;
    int _capacity;
    LRUCache(int capacity) : _capacity(capacity)
    {
        // do intialization if necessary
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        
        auto it = _table.find(key);
        if(it == _table.end())
            return -1;

        _lru.splice(_lru.begin(), _lru, it->second);
        return _lru.front().second;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        
        auto it = _table.find(key);
        if(it != _table.end())
        {
            _lru.splice(_lru.begin(), _lru, it->second);
            _lru.front().second = value;
        }
        else
        {
            if(_lru.size() == _capacity)
            {
                _table.erase(_lru.back().first);
                _lru.pop_back();
            }
            _lru.push_front(make_pair(key, value));
            _table[key] = _lru.begin();
        }
    }
};
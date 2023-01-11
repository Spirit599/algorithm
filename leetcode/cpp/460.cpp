class LFUCache {
public:
    struct node {
        int k;
        int v;
        int f;
    };
    unordered_map<int, list<node>> freqTable;
    unordered_map<int, list<node>::iterator> keyTable;
    int minFreq;
    int capacity;
    LFUCache(int capacity) {

        minFreq = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {

        if(capacity == 0)
            return -1;

        auto it = keyTable.find(key);
        if(it == keyTable.end())
            return -1;

        int ferq = it->second->f;
        int val = it->second->v;
        
        auto& rmList = freqTable[ferq];
        rmList.erase(it->second);
        if(rmList.size() == 0 && minFreq == ferq)
            ++minFreq;

        freqTable[ferq + 1].push_front({key, val, ferq + 1});
        it->second = freqTable[ferq + 1].begin();

        return val;
    }
    
    void put(int key, int value) {

        if(capacity == 0)
            return ;

        auto it = keyTable.find(key);
        if(it == keyTable.end())
        {
            if(capacity == keyTable.size())
            {
                auto& minList = freqTable[minFreq];
                int rmKey = minList.back().k;
                minList.pop_back();
                keyTable.erase(rmKey);
            }
            minFreq = 1;
            freqTable[1].push_front({key, value, 1});
            keyTable[key] = freqTable[1].begin();

        }
        else
        {
            int ferq = it->second->f;
            auto& rmList = freqTable[ferq];
            rmList.erase(it->second);
            if(rmList.size() == 0 && minFreq == ferq)
                ++minFreq;
            freqTable[ferq + 1].push_front({key, value, ferq + 1});
            it->second = freqTable[ferq + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
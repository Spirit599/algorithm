class AllOne {
public:

    unordered_map<string, list<pair<string, int>>::iterator> keyTable;
    map<int, list<pair<string, int>>> freqTable;

    AllOne() {
    }
    
    void inc(string key) {

        auto it = keyTable.find(key);
        if(it == keyTable.end())
        {
            auto psi = make_pair(key, 1);
            freqTable[1].push_front(psi);
            keyTable[key] = freqTable[1].begin();
        }
        else
        {
            int freq = it->second->second;
            auto& rmList = freqTable[freq];
            rmList.erase(it->second);
            if(rmList.size() == 0)
                freqTable.erase(freq);
            freqTable[freq + 1].push_front(make_pair(key, freq + 1));
            it->second = freqTable[freq + 1].begin();
        }
    }
    
    void dec(string key) {

        auto it = keyTable.find(key);
        if(it == keyTable.end())
            return ;
        int freq = it->second->second;
        auto& rmList = freqTable[freq];
        rmList.erase(it->second);
        if(rmList.size() == 0)
            freqTable.erase(freq);
        if(freq != 1)
        {
            freqTable[freq - 1].push_front(make_pair(key, freq - 1));
            it->second = freqTable[freq - 1].begin();
        }
        else
        {
            keyTable.erase(it);
        }

    }
    
    string getMaxKey() {

        if(freqTable.empty())
            return "";

        auto itLast = freqTable.end();
        --itLast;
        return itLast->second.front().first;
    }
    
    string getMinKey() {

        if(freqTable.empty())
            return "";

        auto itFirst = freqTable.begin();
        return itFirst->second.front().first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
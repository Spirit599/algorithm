class MapSum {
private:
    unordered_map<string, int> um;
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        um[key] = val;
    }
    
    int sum(string prefix) {

        int ans = 0;
        for(auto kav : um)
        {
            if(kav.first.substr(0, prefix.size()) == prefix)
            {
                ans += kav.second;
            }
        }
        return ans;

    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
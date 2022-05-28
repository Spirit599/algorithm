//二分
//哈希嵌套
//哈希嵌套map

class TimeMap {
private:
    unordered_map<string, map<int, string>> um;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {

        um[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {

        if(um.count(key) == 1)
        {
            if(um[key].upper_bound(timestamp) == um[key].begin())
            {
                return "";
            }
            else
            {
                return (--um[key].upper_bound(timestamp))->second;
            }
        }
        else
        {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
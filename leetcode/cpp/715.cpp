class RangeModule {
public:
    set<pair<int, int>> memo;
    RangeModule() {

    }
    
    void addRange(int left, int right) {

        int start = left;
        int end = right - 1;
        auto it = memo.lower_bound(make_pair(start - 1, -1));

        while(it != memo.end())
        {
            if(end + 1 < it->second)
                break;
            start = min(start, it->second);
            end = max(end, it->first);
            memo.erase(it++);
        }
        memo.emplace(end, start);
    }
    
    bool queryRange(int left, int right) {

        int start = left;
        int end = right - 1;
        auto it = memo.lower_bound(make_pair(start, -1));

        if(it == memo.end() || it->second > start || it->first < end)
            return false;
        else
            return true;
    }
    
    void removeRange(int left, int right) {

        int start = left;
        int end = right - 1;
        auto it = memo.lower_bound(make_pair(start, -1));

        if(it == memo.end())
            return ;

        int firstStart = it->second;
        int firstEnd = it->first;
        int lastStart = it->second;
        int lastEnd = it->first;


        while(it != memo.end())
        {
            if(end < it->second)
                break;
            lastStart = it->second;
            lastEnd = it->first;
            memo.erase(it++);
        }

        if(firstStart < start && start <= firstEnd)
        {
            memo.emplace(start - 1, firstStart);
        }
        if(end < lastEnd && lastStart <= end)
        {
            memo.emplace(lastEnd, end + 1);
        }

    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
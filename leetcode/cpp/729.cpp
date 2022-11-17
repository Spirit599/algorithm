class MyCalendar {
public:
    set<pair<int, int>> memo;
    MyCalendar() {

    }
    
    bool book(int start, int end) {

        auto it = memo.lower_bound(make_pair(start + 1, end));
        if(it != memo.end())
        {
            if(it->first < end)
                return false;
        }
        
        if(it != memo.begin())
        {
            --it;
            if(it->second > start)
                return false;
        }
        memo.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
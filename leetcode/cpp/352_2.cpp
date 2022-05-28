#define LENGTH (10001)

class SummaryRanges {
private:
    vector<int> inquire;
    map<int ,int> start;
    map<int ,int> end;

public:
    SummaryRanges() : inquire(LENGTH) {
    }
    
    void addNum(int val) {
        if(inquire[val] == 0)
        {
            if(val - 1 >= 0 && inquire[val - 1] == 1 && val + 1 < LENGTH && inquire[val + 1] == 1)
            {
                int start1 = end[val - 1];
                int start2 = val + 1;
                int end1 = val - 1;
                int end2 = start[val + 1];
                start[start1] = end2;
                end[end2] = start1;
                start.erase(start2);
                end.erase(end1);
            }
            else if(val - 1 >= 0 && inquire[val - 1] == 1)
            {
                int start1 = end[val - 1];
                end.erase(val - 1);
                start[start1] = val;
                end[val] = start1;
            }
            else if(val + 1 < LENGTH && inquire[val + 1] == 1)
            {
                int end1 = start[val + 1];
                start.erase(val + 1);
                start[val] = end1;
                end[end1] = val;
            }
            else
            {
                start[val] = val;
                end[val] = val;
            }
            inquire[val] = 1;
        }
    }
    
    vector<vector<int>> getIntervals() {

        vector<vector<int>> ret;

        for(auto item : start)
        {
            ret.push_back({item.first, item.second});
        }

        //sort(ret.begin(), ret.end(), cmp);
        return ret;

    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
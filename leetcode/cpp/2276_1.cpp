class CountIntervals {
public:
    map<int, int> memo;
    int sum = 0;
    CountIntervals()
    {
    }
    
    void add(int left, int right) {


        auto it = memo.lower_bound(left - 1);
        while(it != memo.end())
        {
            int nextRight = it->first;
            int nextLeft = it->second;
            //printf("%d %d %d %d\n", left,right,nextLeft,nextRight);
            if(nextLeft > right + 1)
                break;
            left = min(left, nextLeft);
            right = max(right, nextRight);
            printf("%d %d %d %d\n", left,right,nextLeft,nextRight);
            sum -= nextRight - nextLeft + 1;
            memo.erase(it++);
        }
        memo[right] = left;
        sum += right - left + 1;
    }
    
    int count() {
        return sum;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
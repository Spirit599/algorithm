// 动态开点 线段树

class CountIntervals {
public:
    int ll;
    int rr;
    int sum;
    CountIntervals* leftNode = nullptr;
    CountIntervals* rightNode = nullptr;
    CountIntervals() : ll(0), rr(1e9), sum(0)
    {
    }
    CountIntervals(int l, int r) : ll(l), rr(r), sum(0)
    {
    }
    
    void add(int left, int right) {

        //printf("%d %d %d %d\n", left, right, ll, rr);
        if(sum == rr - ll + 1)
            return ;
        if(left <= ll && rr <= right)
        {
            sum = rr - ll + 1;
            return ;
        }
        if(left > rr || ll > right)
            return ;
        int mid = (ll + rr) >> 1;
        if(leftNode == nullptr)
            leftNode = new CountIntervals(ll, mid);
        if(rightNode == nullptr)
            rightNode = new CountIntervals(mid + 1, rr);
        leftNode->add(left, right);
        rightNode->add(left, right);
        sum = leftNode->sum + rightNode->sum;
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
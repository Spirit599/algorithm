class Solution {
public:
    struct status
    {
        int num;
        int index;
        int ptr;
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int n = nums.size();
        int maxx = INT_MIN;
        int minn = INT_MAX;

        auto cmp1 = [](const status& sta1, const status& sta2) {
            return sta1.num > sta2.num;
        };
        priority_queue<status, vector<status>, decltype(cmp1)> pq(cmp1);
        for(int i = 0; i < n; ++i)
        {
            maxx = max(maxx, nums[i][0]);
            minn = min(minn, nums[i][0]);
            pq.push({nums[i][0], i, 0});
        }
        int maxDif = maxx - minn;
        int ansLeft = minn;
        int ansRight = maxx;
        while(1)
        {
            status cur = pq.top();
            pq.pop();
            ++(cur.ptr);
            if(cur.ptr == nums[cur.index].size())
                break;
            int addNum = nums[cur.index][cur.ptr];
            pq.push({addNum, cur.index, cur.ptr});
            minn = pq.top().num;
            maxx = max(maxx, addNum);
            if(maxDif > maxx - minn)
            {
                maxDif = maxx - minn;
                ansLeft = minn;
                ansRight = maxx;
            }
        }

        return {ansLeft, ansRight};
    }
};
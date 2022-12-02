// 单调队列

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        deque<pair<int, int>> dq;
        int ans = nums[0];
        dq.emplace_back(nums[0], 0);
        int n = nums.size();

        for(int i = 1; i < n; ++i)
        {
            int pre = 0;
            while(!dq.empty() && dq.front().second + k < i)
                dq.pop_front();
            pre = max(dq.front().first, pre);
            int val = pre + nums[i];
            while(!dq.empty() && dq.back().first <= val)
                dq.pop_back();
            ans = max(ans, val);
            dq.emplace_back(val, i);
        }

        return ans;
    }
};
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        deque<pair<int, long long>> deq;
        long long sum = 0;
        deq.push_back(make_pair(-1, sum));

        int n = nums.size();
        int ans = n + 1;
        for(int i = 0; i < n; ++i)
        {
            sum += nums[i];
            while(!deq.empty() && deq.front().second + k <= sum)
            {
                ans = min(ans, i - deq.front().first);
                deq.pop_front();
            }
            while(!deq.empty() && deq.back().second >= sum)
                deq.pop_back();
            deq.push_back(make_pair(i, sum));
        }

        if(ans != n + 1)
            return ans;
        else
            return -1;
    }
};
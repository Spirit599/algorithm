typedef pair<long long, int> plli;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        long long tot = 0;
        for(int& num : nums)
        {
            if(num > 0)
                tot += num;
            else
                num = -num;
        }

        sort(nums.begin(), nums.end());

        priority_queue<plli, vector<plli>, greater<plli>> pq;
        pq.emplace(0, 0);
        int n = nums.size();

        --k;
        while(k--)
        {
            auto [sum, idx] = pq.top();
            pq.pop();
            if(idx < n)
            {
                pq.emplace(sum + nums[idx], idx + 1);
                if(idx)
                    pq.emplace(sum + nums[idx] - nums[idx - 1], idx + 1);
            }
        }

        return tot - pq.top().first;
    }
};
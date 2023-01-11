class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int numGcd = numsDivide[0];
        int n = numsDivide.size();

        for(int i = 0; i < n; ++i)
            numGcd = gcd(numGcd, numsDivide[i]);

        int m = nums.size();
        unordered_map<int, int> memo;
        for(int i = 0; i < m; ++i)
            ++memo[nums[i]];

        vector<pair<int, int>> preSum;
        preSum.emplace_back(0, 0);
        for(auto& kv : memo)
            preSum.emplace_back(kv.first, kv.second);

        sort(preSum.begin(), preSum.end());
        int ps = preSum.size();
        for(int i = 1; i < ps; ++i)
            preSum[i].second += preSum[i - 1].second;

        vector<int> base;
        for(int i = 1; i * i <= numGcd; ++i)
        {
            if(numGcd % i == 0)
            {
                base.emplace_back(i);
                base.emplace_back(numGcd / i);
            }
        }
        sort(base.begin(), base.end());

        int bs = base.size();
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < ps && ptr2 < bs)
        {
            if(preSum[ptr1].first == base[ptr2])
                return preSum[ptr1 - 1].second;
            else if(preSum[ptr1].first < base[ptr2])
                ++ptr1;
            else
                ++ptr2;
        }

        return -1;
    }
};
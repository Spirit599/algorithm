class Solution {
public:
    bool canCross(vector<int>& stones) {

        int n = stones.size();
        unordered_set<long long> dp[n];
        dp[0].insert(0);

        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                long long key = stones[i] - stones[j];
                if(dp[j].count(key - 1) || dp[j].count(key) || dp[j].count(key + 1))
                    dp[i].insert(key);
            }
        }

        return dp[n - 1].size() != 0;

    }
};
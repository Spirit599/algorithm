class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        
        int n = stones.size();
        for(int i = 1; i < n; ++i)
            stones[i] += stones[i - 1];

        int dp = 0;
        int maxn = INT_MIN;
        for(int i = n - 1; i >= 1; --i)
        {
            maxn = max(maxn, stones[i] - dp);
            dp = maxn;
            printf("%d\n", dp);
        }

        return dp;
    }
};
//dp 动态规划
//哈希表 hash


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        bool visit[200005];
        memset(visit, 0, sizeof(visit));

        int dp[200005];
        memset(dp, 0, sizeof(dp));
        int ans = 0;

        for (int i = 0; i < arr.size(); ++i)
        {
            int cur = arr[i] + 100001;
            if(!visit[cur - difference])
            {
                dp[cur] = 1;
            }
            else
            {
                dp[cur] = max(dp[cur], dp[cur - difference] + 1);
            }
            visit[cur] = true;
            ans = max(ans, dp[cur]);
        }

        return ans;
    }
};
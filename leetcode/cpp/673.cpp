class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int ans = 0;
        map<int, int, greater<int>> memo;
        int n = nums.size();
        pair<int, int> dp[n];
        for(int i = 0; i < n; ++i)
        {
            map<int, int, greater<int>> cur;
            cur[0] = 1;
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] < nums[i])
                    cur[dp[j].first] += dp[j].second;
            }
            auto it = cur.begin();
            // for(auto& kv : cur)
            //     printf("%d %d | ", kv.first,kv.second);
            // printf("\n");
            memo[it->first + 1] += it->second;
            dp[i] = make_pair(it->first + 1, it->second);
            // printf("dp %d %d\n", it->first + 1, it->second);
        }

        return memo.begin()->second;
    }
};
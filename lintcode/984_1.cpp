// 984 · 等差切片 II - 子序列

class Solution {
public:
    /**
     * @param a: an array
     * @return: the number of arithmetic subsequence slices in the array A
     */
    int numberOfArithmeticSlices(vector<int> &a) {
        
        int n = a.size();
        vector<unordered_map<long long, int>> dp(n);

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                long long diff = 1ll * a[i] - a[j];
                auto it = dp[j].find(diff);
                int cnt = 0;
                if(it == dp[j].end())
                    cnt = 0;
                else
                    cnt = dp[j][diff];

                ans += cnt;
                dp[i][diff] += cnt + 1;
            }
        }

        return ans;
    }
};
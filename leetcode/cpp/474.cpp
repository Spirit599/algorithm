class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<pair<int, int>> weight;
        for(string& str : strs)
        {
            int cnt0 = 0;
            int cnt1 = 0;
            for(char c : str)
            {
                if(c == '0')
                    ++cnt0;
                else
                    ++cnt1;
            }
            weight.push_back(make_pair(cnt0, cnt1));
        }

        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for(auto& pii : weight)
        {
            int x = pii.first;
            int y = pii.second;
            printf("%d %d\n", x,y);
            for(int i = m; i >= x; --i)
            {
                for(int j = n; j >= y; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
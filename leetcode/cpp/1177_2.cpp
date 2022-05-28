//hash
//前缀和
//手动实现

const int MAX_HASH = 26;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        int n = s.size();
        // vector<unordered_map<char, int>> vu(n);
        // unordered_map<char, int> um;
        int dp[n][MAX_HASH];
        memset(dp, 0, sizeof(dp));
        dp[0][s[0] - 'a'] = 1;

        for (int i = 1; i < n; ++i)
        {
            memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
            dp[i][s[i] - 'a'] = dp[i - 1][s[i] - 'a'] + 1;
            // for (int j = 0; j < MAX_HASH; ++j)
            // {
            //     cout<<(char)j + 'a'<<" "<<dp[i][s[0] - 'a']
            // }
        }

        vector<bool> ans;
        int m = queries.size();
        for (int i = 0; i < m; ++i)
        {
            int detal = 0;

            if(queries[i][0] != 0)
            {
                for (int j = 0; j < MAX_HASH; ++j)
                {
                    detal += (dp[queries[i][1]][j] - dp[queries[i][0] - 1][j]) % 2;
                }
            }
            else
            {
                for (int j = 0; j < MAX_HASH; ++j)
                {
                    detal += dp[queries[i][1]][j] % 2;
                }
            }
            cout<<detal<<endl;
            detal = detal / 2;

            if(detal > queries[i][2])
                ans.push_back(false);
            else
                ans.push_back(true);

        }

        return ans;
    }
};
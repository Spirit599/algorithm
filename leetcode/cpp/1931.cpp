const int mod = 1e9 + 7;

class Solution {
public:
    int colorTheGrid(int m, int n) {

        vector<vector<char>> patterns;
        vector<char> cur;

        function<void(int)> dfs = [&](int depth) {

            if(depth == m)
            {
                patterns.emplace_back(cur);
                return;
            }

            if(cur.empty() || cur.back() != 'a')
            {
                cur.push_back('a');
                dfs(depth + 1);
                cur.pop_back();
            }
            if(cur.empty() || cur.back() != 'b')
            {
                cur.push_back('b');
                dfs(depth + 1);
                cur.pop_back();
            }
            if(cur.empty() || cur.back() != 'c')
            {
                cur.push_back('c');
                dfs(depth + 1);
                cur.pop_back();
            }
        };

        
        dfs(0);


        int patternSize = patterns.size();
        vector<int> patternConvert[patternSize];
        for(int i = 0; i < patternSize; ++i)
        {
            for(int j = 0; j < patternSize; ++j)
            {
                if(i == j)
                    continue;

                int k = 0;
                for(; k < m; ++k)
                {
                    if(patterns[i][k] == patterns[j][k])
                        break;
                }
                if(k == m)
                    patternConvert[i].emplace_back(j);
            }
        }


        int dp[n][patternSize];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < patternSize; ++i)
            dp[0][i] = 1;


        for(int i = 0; i < n - 1; ++i)
        {
            for(int p = 0; p < patternSize; ++p)
            {
                for(int nextp : patternConvert[p])
                {
                    dp[i + 1][nextp] = (dp[i + 1][nextp] + dp[i][p]) % mod;
                }
            }
        }

        int ans = 0;
        for(int p = 0; p < patternSize; ++p)
            ans = (ans + dp[n - 1][p]) % mod;


        return ans;
    }
};
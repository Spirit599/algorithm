class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> pi;
    int helper(string& s, string& evil) {

        int n = s.size();
        int m = evil.size();
        int dp[n][m];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, bool)> dfs = [&](int idx, int matchIdx, bool isLimited) -> int {

            if(matchIdx == m)
                return 0;
            if(idx == n)
                return 1;
            if(!isLimited && dp[idx][matchIdx] != -1)
                return dp[idx][matchIdx];
            
            int ret = 0;
            char start = 'a';
            char end = isLimited ? s[idx] : 'z';

            for(char i = start; i <= end; ++i)
            {
                int mIdx = matchIdx - 1;
                while(mIdx >= 0 && evil[mIdx + 1] != i)
                {
                    mIdx = pi[mIdx] - 1;
                }
                if(evil[mIdx + 1] == i)
                    ++mIdx;

                ret = (ret + dfs(idx + 1, mIdx + 1, isLimited && i == s[idx])) % mod;
            }

            if(!isLimited)
                dp[idx][matchIdx] = ret;
            return ret;
        };

        return dfs(0, 0, true);
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {

        int m = evil.size();
        pi.resize(m);
        pi[0] = 0;

        for(int i = 1; i < m; ++i)
        {
            int j = pi[i - 1];
            while(j != 0 && evil[j] != evil[i])
                j = pi[j - 1];
            if(evil[j] == evil[i])
                ++j;
            pi[i] = j;
        }

        return (helper(s2, evil) - helper(s1, evil) + (s1.find(evil) == string::npos) + mod) % mod;
    }
};
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {

        int n = target.size();
        int S = 1 << n;
        int dp[S];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        int inf = 0x3f3f3f3f;
        int stickersSize = stickers.size();
        int cnt[stickersSize][26];
        int curCnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < stickersSize; ++i)
        {
            int strSize = stickers[i].size();
            for(int j = 0; j < strSize; ++j)
            {
                ++cnt[i][stickers[i][j] - 'a'];
            }
        }


        function<int(int)> dfs = [&](int curS) -> int {

            if(dp[curS] != -1)
                return dp[curS];

            dp[curS] = inf;
            for(int i = 0; i < stickersSize; ++i)
            {
                memcpy(curCnt, cnt[i], sizeof(curCnt));
                int leftMask = curS;
                for(int j = 0; j < n; ++j)
                {
                    if(((curS >> j) & 1) && curCnt[target[j] - 'a'])
                    {
                        --curCnt[target[j] - 'a'];
                        leftMask ^= (1 << j);
                    }
                }

                if(leftMask < curS)
                    dp[curS] = min(dp[curS], dfs(leftMask) + 1);
            }

            return dp[curS];
        };



        int ans = dfs(S - 1);
        if(ans > n)
            return -1;
        else
            return ans;
    }
};
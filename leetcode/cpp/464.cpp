// 博弈
// 状态压缩

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        
        int allSum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if(allSum < desiredTotal)
            return false;


        int S = 1 << maxChoosableInteger;
        int dp[S];
        memset(dp, -1, sizeof(dp));


        function<bool(int, int)> dfs = [&](int S, int desiredTotal) -> bool {

            if(dp[S] != -1)
                return dp[S];


            bool ret = false;

            for(int k = 0; k < maxChoosableInteger; ++k)
            {
                if(((S >> k) & 1) == 0) // 第k位还没选
                {
                    int num = k + 1;
                    if(num >= desiredTotal)
                    {
                        ret = true;
                        break;
                    }

                    ret = ret || !dfs(S | (1 << k), desiredTotal - num);
                    if(ret)
                        break;

                }
            }

            return dp[S] = ret;
        };

        return dfs(0, desiredTotal);
    }
};
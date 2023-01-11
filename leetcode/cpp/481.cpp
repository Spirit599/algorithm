class Solution {
public:
    int magicalString(int n) {

        if(n <= 3)
            return 1;

        int dp[n + 3];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 2;

        int fast = 4;
        int slow = 3;
        while(fast <= n)
        {
            int num = dp[slow];
            int cur = 3 - dp[fast - 1];
            // printf("%d\n", cur);

            dp[fast++] = cur;
            if(num == 2)
                dp[fast++] = cur;
            ++slow;
        }


        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            // printf("%d ", dp[i]);
            if(dp[i] == 1)
                ++ans;
        }
        return ans;
    }
};
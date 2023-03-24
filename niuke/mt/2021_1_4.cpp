#include <bits/stdc++.h>
using namespace std;

struct info
{
    int cost;
    int val;
    bool isOne;
};

int main() {
    
    int n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    info dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i)
        dp[i][i] = {0, nums[i], true};

    for(int len = 2; len <= n; ++len)
    {
        for(int start = 0; start + len - 1 < n; ++start)
        {
            int end = start + len - 1;
            for(int split = start; split < end; ++split)
            {
                auto& ll = dp[start][split];
                auto& rr = dp[split + 1][end];
                bool ok = ll.isOne && rr.isOne &&
                        ll.val == rr.val && ll.val != -1;
                int cost = ll.cost + rr.cost + ok;
                if(cost > dp[start][end].cost)
                {
                    if(ok)
                        dp[start][end] = {cost, ll.val + 1, true};
                    else
                        dp[start][end] = {cost, -1, false};
                }
            }
        }
    }

    cout<<dp[0][n - 1].cost<<endl;

    return 0;
}
// 64 位输出请用 printf("%lld")
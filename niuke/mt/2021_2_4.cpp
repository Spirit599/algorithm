#include <bits/stdc++.h>
using namespace std;


    


int main() {
    
    int n,a,b;
    cin >> n >> a >> b;

    int dp[a + 1][b + 1];
    memset(dp, 0, sizeof(dp));

    int x,y;
    while(n--)
    {
        cin >> x >> y;
        for(int i = a; i >= 0; --i)
        {
            for(int j = b; j >= 0; --j)
            {
                if(i && j)
                    dp[i][j] = max({dp[i][j], dp[i - 1][j] + x, dp[i][j - 1] + y});
                else if(i)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + x);
                else if(j)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + y);
            }
        }
    }

    cout<<dp[a][b]<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
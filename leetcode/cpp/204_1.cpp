// Eratosthenes
// 质数

class Solution {
public:
    int countPrimes(int n) {

        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));

        int ans = 0;
        for(int i = 2; i < n; ++i)
        {
            if(!vis[i])
            {
                ++ans;
                for(int k = i; k < n; k += i)
                {
                    vis[k] = true;
                }
            }
        }

        return ans;
    }
};
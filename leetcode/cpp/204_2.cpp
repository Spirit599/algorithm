// 欧拉
// 质数

class Solution {
public:
    int countPrimes(int n) {

        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        int primes[n];
        int cnt = 0;

        for(int i = 2; i < n; ++i)
        {
            if(!vis[i])
                primes[cnt++] = i;
            for(int j = 0; j < cnt && i * primes[j] < n; ++j)
            {
                vis[i * primes[j]] = true;
                if(primes[j] % i == 0)
                    break;
            }
        }

        return cnt;
    }
};
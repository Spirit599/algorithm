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

// 欧拉
// 质数

class Solution {
public:
    int countPrimes(int n) {

        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        int primes[n + 1];
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
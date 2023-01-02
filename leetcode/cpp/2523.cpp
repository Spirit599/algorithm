class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        int n = 1e6 + 5;
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        vector<int> isPrime;

        for(int i = 2; i <= n; ++i)
        {
            if(!vis[i])
            {
                isPrime.emplace_back(i);
                for(int j = 2 * i; j <= n; j += i)
                    vis[j] = true;
            }
        }

        vector<int> candidate;
        for(int prime : isPrime)
        {
            if(prime >= left && prime <= right)
            {
                candidate.emplace_back(prime);
                printf("%d\n", prime);
            }
        }

        int m = candidate.size();
        if(m <= 1)
            return {-1, -1};
        int dif = INT_MAX;
        int a, b;
        for(int i = 0; i < m - 1; ++i)
        {
            if(candidate[i + 1] - candidate[i] < dif)
            {
                dif = candidate[i + 1] - candidate[i];
                a = candidate[i];
                b = candidate[i + 1];
            }
        }

        return {a, b};
    }
};
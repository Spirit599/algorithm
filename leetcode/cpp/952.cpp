class unionFind {
private:
    vector<int> fa;
    vector<int> height;
public:
    unionFind(int n)
    {
        fa = vector<int>(n, -1);
        height = vector<int>(n, 0);
    }

    int findFa(int x)
    {
        while(fa[x] != -1)
            x = fa[x];
        return x;
    }

    void unionNode(int x, int y)
    {
        int fx = findFa(x);
        int fy = findFa(y);
        if(fx == fy)
            return;

        if(height[fx] < height[fy])
            fa[fx] = fy;
        else if(height[fx] > height[fy])
            fa[fy] = fx;
        else
        {
            fa[fx] = fy;
            ++height[fy];
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {

        int n = *max_element(nums.begin(), nums.end());
        unionFind uf(n + 1);

        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        vector<int> primes;
        for(int i = 2; i <= n; ++i)
        {
            if(!vis[i])
            {
                primes.emplace_back(i);
                for(int j = 2 * i; j <= n; j += i)
                {
                    vis[j] = true;
                }
            }
        }


        for(int num : nums)
        {
            int cnum = num;
            for(int prime : primes)
            {
                if(cnum < prime * prime)
                    break;
                if(cnum % prime != 0)
                    continue;
                while(cnum % prime == 0)
                    cnum /= prime;
                uf.unionNode(num, prime);
            }
            if(cnum > 1)
                uf.unionNode(num, cnum);
        }

        int cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;

        for(int num : nums)
        {
            int fa = uf.findFa(num);
            ++cnt[fa];
            ans = max(ans, cnt[fa]);
        }



        return ans;
    }
};
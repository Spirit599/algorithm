class unionFind {
private:
    vector<int> fa;
    vector<int> height;
    vector<int> unionSize;
    int n;
public:
    unionFind(int n)
    {
        this->n = n;
        fa.resize(n, -1);
        height.resize(n, 0);
        unionSize.resize(n, 1);
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
        {
            fa[fx] = fy;
            unionSize[fy] += unionSize[fx];
        }
        else if(height[fx] > height[fy])
        {
            fa[fy] = fx;
            unionSize[fx] += unionSize[fy];
        }
        else
        {
            fa[fx] = fy;
            ++height[fy];
            unionSize[fy] += unionSize[fx];
        }
    }

    bool isConnection(int x, int y)
    {
        return findFa(x) == findFa(y);
    }

    int isolatedNum()
    {
        int ret = 0;
        for(int i = 0; i < n; ++i)
        {
            if(fa[i] == -1)
                ++ret;
        }
        return ret;
    }

    int UnionSize(int x)
    {
        int fx = findFa(x);
        return unionSize[fx];
    }
};

class Solution {
public:
    vector<int> getBase(int n)
    {
        vector<int> ret;
        for(long long i = 2; i * i <= n; ++i)
        {
            if(n % i == 0)
            {
                ret.push_back(i);
                while(n % i == 0)
                {
                    n = n / i;
                }
            }
        }
        if(n != 1)
            ret.push_back(n);
        return ret;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        

        if(nums.size() == 1)
            return true;
        
        const int maxn = 100005;
        unionFind uf(maxn);
        bool vis[maxn];
        memset(vis, 0, sizeof(vis));

        for(int x : nums)
        {
            if(x == 1)
                return false;
            vector<int> ret = getBase(x);
            int m = ret.size();

            vis[ret[0]] = true;
            for(int i = 1; i < m; ++i)
            {
                vis[ret[i]] = true;
                uf.unionNode(ret[i], ret[i - 1]);
            }
        }

        int cnt = 0;
        int v = -1;
        for(int i = 0; i < maxn; ++i)
        {
            if(vis[i])
            {
                ++cnt;
                v = i;
                // printf("%d ", i);
            }
        }

        // printf("\n%d %d\n",uf.UnionSize(v),cnt);

        return uf.UnionSize(v) == cnt;
    }
};
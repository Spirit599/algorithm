class unionFind {
private:
    vector<int> fa;
    vector<int> height;
public:
    unionFind(int n)
    {
        fa.resize(n, -1);
        height.resize(n, 0);
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
        }
        else if(height[fx] > height[fy])
        {
            fa[fy] = fx;
        }
        else
        {
            fa[fx] = fy;
            ++height[fy];
        }
    }

    bool isConnection(int x, int y)
    {
        return findFa(x) == findFa(y);
    }
};


class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {

        unionFind uf(n + 1);
        for(int th = threshold + 1; th <= n; ++th)
        {
            for(int a = th, b = 2 * th; b <= n; a += th, b += th)
            {
                uf.unionNode(a, b);
            }
        }

        vector<bool> ans;
        for(auto& query : queries)
        {
            ans.emplace_back(uf.isConnection(query[0], query[1]));
        }
        return ans;
    }
};
class unionFind {
private:
    vector<int> fa;
    vector<int> height;
    int n;
public:
    unionFind(int n)
    {
        this->n = n;
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

    int islandNum()
    {
        int ret = 0; 
        for(int i = 0; i < n; ++i)
        {
            if(fa[i] == -1)
                ++ret;
        }
        return ret;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int cn = connections.size();
        if(cn + 1 < n)
            return -1;
        unionFind uf(n);
        for(auto& c : connections)
        {
            uf.unionNode(c[0], c[1]);
        }

        return uf.islandNum() - 1;

    }
};
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
};
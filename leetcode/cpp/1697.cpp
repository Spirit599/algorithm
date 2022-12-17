class unionFind {
private:
    vector<int> fa;
    vector<int> height;
    vector<int> unionSize;
public:
    unionFind(int n)
    {
        fa.resize(n, -1);
        height.resize(n, 0);
        unionSize.resize(n, 0);
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
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        sort(edgeList.begin(), edgeList.end(), [](vector<int>& v1, vector<int>& v2) {return v1[2] < v2[2];});
        int querySize = queries.size();
        for(int i = 0; i < querySize; ++i)
            queries[i].emplace_back(i);
        sort(queries.begin(), queries.end(), [](vector<int>& v1, vector<int>& v2) {return v1[2] < v2[2];});
        int i = 0;
        int edgeSize = edgeList.size();
        unionFind uf(n);
        vector<bool> ans(querySize);

        for(vector<int>& query : queries)
        {
            while(i < edgeSize && edgeList[i][2] < query[2])
            {
                uf.unionNode(edgeList[i][0], edgeList[i][1]);
                ++i;
            }
            ans[query[3]] = uf.isConnection(query[0], query[1]);
        }

        return ans;
    }
};
struct edge
{
    int cost;
    int from;
    int to;
};
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
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        vector<edge> edges;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }
        sort(edges.begin(), edges.end(), [](const edge& v1, const edge& v2)
        {
            return v1.cost < v2.cost;
        });

        unionFind uf(n);
        int cnt = 0;
        int ans = 0;
        for(auto& edge : edges)
        {
            int from = edge.from;
            int to = edge.to;
            if(uf.isConnection(from, to))
                continue;
            ++cnt;
            uf.unionNode(from, to);
            ans += edge.cost;
            if(cnt == n - 1)
                break;
        }

        return ans;
    }
};
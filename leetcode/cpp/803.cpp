// 逆序并查集

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
        unionSize.resize(n, 1);
    }

    int findFa(int x)
    {
        while(fa[x] != -1)
            x = fa[x];
        return x;
    }

    void mergeNode(int x, int y)
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

    int nodeSize(int x)
    {
        return unionSize[findFa(x)];
    }
};


class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {

        int m = grid.size();
        int n = grid[0].size();

        auto coodToIndex = [&](int x, int y) -> int {
            return x * n + y;
        };

        int roomTop = m * n;
        unionFind uf(roomTop + 1);

        for(vector<int>& hit : hits)
            --grid[hit[0]][hit[1]];

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] != 1)
                    continue;
                if(i == 0)
                {
                    uf.mergeNode(roomTop, coodToIndex(i, j));
                }
                if(j && grid[i][j - 1] == 1)
                    uf.mergeNode(coodToIndex(i, j), coodToIndex(i, j - 1));
                if(i && grid[i - 1][j] == 1)
                    uf.mergeNode(coodToIndex(i, j), coodToIndex(i - 1, j));
            }
        }

        int hitSize = hits.size();
        vector<int> ans(hitSize);
        int dires[] = {-1, 0, 1, 0, -1};
        for(int i = hitSize - 1; i >= 0; --i)
        {
            int x = hits[i][0];
            int y = hits[i][1];
            ++grid[x][y];

            if(grid[x][y] != 1)
                continue;


            int preSum = uf.nodeSize(roomTop);
            
            if(x == 0)
                uf.mergeNode(roomTop, coodToIndex(x, y));

            for(int d = 0; d < 4; ++d)
            {
                int i = x + dires[d];
                int j = y + dires[d + 1];
                if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] < 1)
                    continue;
                uf.mergeNode(coodToIndex(x, y), coodToIndex(i, j));
            }

            int nowSum = uf.nodeSize(roomTop);

            ans[i] = max(nowSum - preSum - 1, 0);
        }

        return ans;
    }
};
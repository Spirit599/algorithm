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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int n = row * col;
        int bottom = n + 1;
        int top = n;
        unionFind uf(n + 2);
        // for(int i = 0; i < col; ++i)
        //     uf.unionNode(top, i);
        // for(int i = 0; i < col; ++i)
        //     uf.unionNode(bottom, (row - 1) * col + i);

        int cellSize = cells.size();
        bool vis[row][col];
        memset(vis, 0, sizeof(vis));
        int dires[] = {-1, 0, 1, 0, -1};
        for(int day = cellSize - 1; day >= 0; --day)
        {
            int x = cells[day][0] - 1;
            int y = cells[day][1] - 1;
            if(x == 0)
                uf.unionNode(top, y);
            if(x == row - 1)
                uf.unionNode(bottom, x * col + y);

            for(int d = 0; d < 4; ++d)
            {
                int i = x + dires[d];
                int j = y + dires[d + 1];
                if(i < 0 || i >= row || j < 0 || j >= col || !vis[i][j])
                    continue;
                uf.unionNode(x * col + y, i * col + j);
            }
            vis[x][y] = true;
            if(uf.isConnection(top, bottom))
                return day;
        }

        return -1;


    }
};
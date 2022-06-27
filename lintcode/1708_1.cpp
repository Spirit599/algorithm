// 1708 · 最短的桥

class Solution {
public:
    /**
     * @param a: 
     * @return: nothing
     */
    int m;
    int n;
    int shortestBridge(vector<vector<int>> &a) {
        
        queue<pair<int, int>> que;
        m = a.size();
        n = a[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        for(int i = 0; i < m; ++i)
        {
            int flag = false;
            for(int j = 0; j < n; ++j)
            {
                if(a[i][j] == 1)
                {
                    add_queue(que, a, visit, i, j);
                    flag = true;
                    break;
                }
                visit[i][j] = true;
            }
            if(flag)
                break;
        }

        int depth = 0;
        int dires[] = {-1, 0, 1, 0, -1};
        while(!que.empty())
        {
            ++depth;
            int k = que.size();
            while(k--)
            {
                pair<int, int> cur = que.front();
                que.pop();
                if(a[cur.first][cur.second] == 1)
                    return depth - 2;

                for(int k = 0; k < 4; ++k)
                {
                    int i = cur.first + dires[k];
                    int j = cur.second + dires[k + 1];
                    if(i < 0 || i >= m || j < 0 || j >= n || visit[i][j])
                        continue;

                    que.push(make_pair(i, j));
                }
            }
        }

        return -1;
    }

    void add_queue(queue<pair<int, int>>& que, vector<vector<int>> &a, vector<vector<bool>> &visit, int cur_i, int cur_j)
    {
        if(cur_i < 0 || cur_i >= m || cur_j < 0 || cur_j >= n || a[cur_i][cur_j] == 0)
            return ;
        a[cur_i][cur_j] = 0;
        visit[cur_i][cur_j] = true;
        que.push(make_pair(cur_i, cur_j));

        add_queue(que, a, visit, cur_i + 1, cur_j);
        add_queue(que, a, visit, cur_i - 1, cur_j);
        add_queue(que, a, visit, cur_i, cur_j + 1);
        add_queue(que, a, visit, cur_i, cur_j - 1);
    }
};
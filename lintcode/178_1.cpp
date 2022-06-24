// 178 · 图是否是树

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        
        int edges_num = edges.size();
        if(edges_num != n - 1)
            return false;

        return check_connected(n, edges);
    }

    bool check_connected(int n, vector<vector<int>> &edges)
    {
        vector<int> undire_edges[n];
        for(vector<int>& edge : edges)
        {
            undire_edges[edge[0]].push_back(edge[1]);
            undire_edges[edge[1]].push_back(edge[0]);
        }

        bool visit[n];
        memset(visit, 0, sizeof(visit));
        queue<int> que;
        que.push(0);
        visit[0] = true;
        int nums = 1;

        while(!que.empty())
        {
            int cur = que.front();
            que.pop();

            for(int next : undire_edges[cur])
            {
                if(!visit[next])
                {
                    visit[next] = true;
                    que.push(next);
                    ++nums;
                }
            }
        }

        return nums == n;
    }
};
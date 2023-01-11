class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int cur, int tagret, vector<int>& path, bool vis[], vector<vector<int>>& graph)
    {
        if(cur == tagret)
        {
            ans.push_back(path);
            return ;
        }
        for(int next : graph[cur])
        {
            if(!vis[next])
            {
                vis[next] = true;
                path.push_back(next);
                dfs(next, tagret, path, vis, graph);
                path.pop_back();
                vis[next] = false;
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        vector<int> path({0});
        vis[0] = true;
        dfs(0, n - 1, path, vis, graph);

        return ans;

    }
};
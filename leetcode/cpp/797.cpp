class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int dst = graph.size() - 1;
        vector<int> path;
        vector<vector<int>> ret;

        function<void(int)> dfs = [&](int cur) {

            if(cur == dst)
                ret.emplace_back(path);

            for(int next : graph[cur])
            {
                path.emplace_back(next);
                dfs(next);
                path.pop_back();
            }
        };

        path.emplace_back(0);
        dfs(0);

        return ret;
    }
};
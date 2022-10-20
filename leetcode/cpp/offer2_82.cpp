class Solution {
public:
    vector<vector<int>> ans;
    int target;
    int n;
    bool vis[105];
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        this->target = target;
        this->n = candidates.size();
        sort(candidates.begin(), candidates.end());
        memset(vis, 0, sizeof(vis));
        vector<int> cur;
        dfs(cur, 0, candidates, 0);
        return ans;
    }
    void dfs(vector<int>& cur, int value, vector<int>& candidates, int depth) {

        // for(int num : cur)
        //     printf("%d ", num);
        // printf("\n");
        // printf("%d %d %d %d\n", value, target, depth, n);
        if(value > target)
            return ;
        else if(value == target)
        {
            ans.push_back(cur);
            return ;
        }
        if(depth == n)
            return ;
        for(int i = depth; i < n; ++i)
        {
            if(i && candidates[i] == candidates[i - 1] && !vis[i - 1])
                continue;
            cur.push_back(candidates[i]);
            vis[i] = true;
            dfs(cur, value + candidates[i], candidates, i + 1);
            vis[i] = false;
            cur.pop_back();
        }
    }
};
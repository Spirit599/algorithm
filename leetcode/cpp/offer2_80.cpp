class Solution {
public:
    int n;
    int k;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {

        this->n = n;
        this->k = k;
        vector<int> cur;
        dfs(cur, 1, 0);
        return ans;
    }
    void dfs(vector<int>& cur, int start, int depth)
    {
        if(depth == k)
        {
            ans.push_back(cur);
            return ;
        }

        for(int i = start; i <= n; ++i)
        {
            cur.push_back(i);
            dfs(cur, i + 1, depth + 1);
            cur.pop_back();
        }
    }
};
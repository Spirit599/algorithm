class Solution {
public:
    vector<string> permutation(string s) {

        vector<string> ans;
        sort(s.begin(), s.end());
        int n = s.size();
        int vis[n];
        memset(vis, 0, sizeof(vis));
        string cur;

        function<void(int, string&)> dfs = [&](int depth, string& cur) {

            if(depth == n)
            {
                ans.emplace_back(cur);
                return ;
            }

            for(int i = 0; i < n; ++i)
            {
                if(i > 0 && s[i] == s[i - 1] && vis[i - 1])
                    continue;
                if(!vis[i])
                {
                    vis[i] = true;
                    cur.push_back(s[i]);
                    dfs(depth + 1, cur);
                    cur.pop_back();
                    vis[i] = false;
                }
            }
        };

        dfs(0, cur);

        return ans;
    }
};
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;
        int leftNum = 0;
        int ll = 0;
        for(char c : s)
        {
            if(c == '(')
                ++ll;
            else if(c == ')')
            {
                if(ll)
                {
                    ++leftNum;
                    --ll;
                }                
            }
        }

        int n = s.size();
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        string cur;
        function<void(int, int, int)> dfs = [&](int depth, int surplus, int left) {

            if(depth == n)
            {
                if(surplus == 0 && left == leftNum)
                    ans.emplace_back(cur);
                return ;
            }
            if(surplus < 0 || left > leftNum)
                return ;

            if(s[depth] == '(')
            {
                dfs(depth + 1, surplus, left);

                if(depth && s[depth] == s[depth - 1] && !vis[depth - 1])
                    return;

                cur.push_back('(');
                vis[depth] = true;
                dfs(depth + 1, surplus + 1, left + 1);
                vis[depth] = false;
                cur.pop_back();

                
                
            }
            else if(s[depth] == ')')
            {
                dfs(depth + 1, surplus, left);

                if(depth && s[depth] == s[depth - 1] && !vis[depth - 1])
                    return;

                cur.push_back(')');
                vis[depth] = true;
                dfs(depth + 1, surplus - 1, left);
                vis[depth] = false;
                cur.pop_back(); 
            }
            else
            {
                cur.push_back(s[depth]);
                vis[depth] = true;
                dfs(depth + 1, surplus, left);
                vis[depth] = false;
                cur.pop_back();
            }
        };

        
        dfs(0, 0, 0);

        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> ans;
    int n;
    vector<vector<string>> partition(string s) {

        vector<string> cur;
        n = s.size();
        dfs(cur, s, 0);
        return ans;
    }
    void dfs(vector<string>& cur, string& s, int depth)
    {
        if(depth == n)
            ans.push_back(cur);

        for(int i = depth; i < n; ++i)
        {
            int len = i - depth + 1;
            string str = s.substr(depth, len);
            if(check(str))
            {
                cur.push_back(str);
                dfs(cur, s, depth + len);
                cur.pop_back();
            }
        }
    }
    bool check(string& str)
    {
        int n = str.size();
        for(int i = 0; i < n / 2; ++i)
        {
            if(str[i] != str[n - i - 1])
                return false;
        }
        return true;
    }
};
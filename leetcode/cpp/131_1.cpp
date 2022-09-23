class Solution {
public:
    vector<vector<string>> ans;

    bool check(string str)
    {
        int n = str.size();
        for(int i = 0; i < n / 2; ++i)
        {
            if(str[i] != str[n - i - 1])
                return false;
        }
        return true;
    }

    void dfs(string& s, int index, int n, vector<string>& cur)
    {
        if(index == n)
            ans.push_back(cur);

        string str;
        for(int i = index; i < n; ++i)
        {
            str.push_back(s[i]);
            if(check(str))
            {
                cur.push_back(str);
                dfs(s, i + 1, n, cur);
                cur.pop_back();
            }
            // else
            // {
            //     break;
            // }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();
        vector<string> cur;
        dfs(s, 0, n, cur);

        return ans;
    }
};
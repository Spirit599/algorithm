class Solution {
public:
    vector<string> letterCasePermutation(string s) {

        vector<string> ans;
        int n = s.size();

        function<void(int, string&)> dfs = [&](int depth, string& cur) ->void {
            if(depth == n)
            {
                ans.push_back(cur);
                return ;
            }
            cur.push_back(s[depth]);
            dfs(depth + 1, cur);
            cur.pop_back();
            if(s[depth] >= 'a' && s[depth] <= 'z')
            {
                cur.push_back(s[depth] - 'a' + 'A');
                dfs(depth + 1, cur);
                cur.pop_back();
            }
            else if(s[depth] >= 'A' && s[depth] <= 'Z')
            {
                cur.push_back(s[depth] - 'A' + 'a');
                dfs(depth + 1, cur);
                cur.pop_back();
            }
        };

        string cur;
        dfs(0, cur);
        return ans;

    }
};
// 427 · 生成括号

class Solution {
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     *          we will sort your return value in output
     */
    void dfs(vector<string>& ans, string& ret, int depth, int matching, int left, int n)
    {
        if(n * 2 == depth)
        {
            ans.push_back(ret);
            return ;
        }

        if(matching == 0 && left < n)
        {
            ret.push_back('(');
            dfs(ans, ret, depth + 1, matching + 1, left + 1, n);
            ret.pop_back();
        }
        else if(left == n)
        {
            ret.push_back(')');
            dfs(ans, ret, depth + 1, matching - 1, left, n);
            ret.pop_back();
        }
        else
        {
            ret.push_back('(');
            dfs(ans, ret, depth + 1, matching + 1, left + 1, n);
            ret.pop_back();
            ret.push_back(')');
            dfs(ans, ret, depth + 1, matching - 1, left, n);
            ret.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string ret;

        dfs(ans, ret, 0, 0, 0, n);

        return ans;
    }
};
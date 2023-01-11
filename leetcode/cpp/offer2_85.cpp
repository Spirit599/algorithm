class Solution {
public:
    int n;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        this->n = n;
        string str;
        dfs(0, 0, 0, str);
        return ans;
    }
    void dfs(int left, int right, int depth, string& cur)
    {
        if(right > left || left > n)
            return ;
        if(depth == 2 * n)
        {
            if(left == right)
            {
                ans.push_back(cur);
            }
            return ;
        }
        cur.push_back('(');
        dfs(left + 1, right, depth + 1, cur);
        cur.pop_back();
        cur.push_back(')');
        dfs(left, right + 1, depth + 1, cur);
        cur.pop_back();
    }
};
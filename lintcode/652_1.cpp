// 652 · 因式分解

class Solution {
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     *          we will sort your return value in output
     */
    vector<vector<int>> getFactors(int n) {
        
        vector<vector<int>> ans;
        vector<int> ret;

        dfs(ans, ret, 2, n);

        return ans; 
    }

    void dfs(vector<vector<int>>& ans, vector<int>& ret, int bigger_factor, int n)
    {
        if(ret.size() != 0)
        {
            ret.push_back(n);
            ans.push_back(ret);
            ret.pop_back();
        }

        int max_factor = sqrt(n);
        for(int i = bigger_factor; i <= max_factor; ++i)
        {
            if(n % i == 0)
            {
                ret.push_back(i);
                dfs(ans, ret, i, n / i);
                ret.pop_back();
            }
        }
    }
};
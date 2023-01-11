class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n1 = str1.size();
        int n2 = str2.size();
        int lcs[n1 + 1][n2 + 1];
        memset(lcs, 0, sizeof(lcs));

        for(int i = 0; i < n1; ++i)
        {
            for(int j = 0; j < n2; ++j)
            {
                if(str1[i] == str2[j])
                    lcs[i + 1][j + 1] = lcs[i][j] + 1;
                else
                    lcs[i + 1][j + 1] = max(lcs[i + 1][j], lcs[i][j + 1]);
            }
        }

        vector<int> v1;
        vector<int> v2;

        function<void(int, int)> dfs = [&](int i, int j) {

            if(i == 0 || j == 0)
                return ;
            else if(lcs[i][j] == lcs[i - 1][j])
                dfs(i - 1, j);
            else if(lcs[i][j] == lcs[i][j - 1])
                dfs(i, j - 1);
            else
            {
                dfs(i - 1, j - 1);
                v1.emplace_back(i - 1);
                v2.emplace_back(j - 1);
            }
        };

        dfs(n1, n2);
        int k = v1.size();
        string ans;
        int pre1 = 0;
        int pre2 = 0;
        for(int i = 0; i < k; ++i)
        {
            for(int j = pre1; j < v1[i]; ++j)
                ans.push_back(str1[j]);
            for(int j = pre2; j < v2[i]; ++j)
                ans.push_back(str2[j]);
            pre1 = v1[i] + 1;
            pre2 = v2[i] + 1;
            ans.push_back(str1[v1[i]]);
        }
        for(int j = pre1; j < n1; ++j)
            ans.push_back(str1[j]);
        for(int j = pre2; j < n2; ++j)
            ans.push_back(str2[j]);



        return ans;
    }
};
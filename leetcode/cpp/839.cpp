class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();
        int strSize = strs[0].size();

        auto checkOk = [&](int i, int j) -> bool {

            int dif = 0;
            int idx1 = -1;
            int idx2 = -1;
            for(int k = 0; k < strSize; ++k)
            {
                if(strs[i][k] != strs[j][k])
                {
                    ++dif;
                    if(idx1 == -1)
                        idx1 = k;
                    else if(idx2 == -1)
                        idx2 = k;
                }
                if(dif > 2)
                    return false;
            }

            if(dif == 0)
                return true;
            else if(dif == 1)
                return false;
            
            return strs[i][idx1] == strs[j][idx2] && strs[i][idx2] == strs[j][idx1];
        };

        int vis[n];
        memset(vis, 0, sizeof(vis));
        function<void(int)> dfs = [&](int cur) {

            if(vis[cur])
                return ;
            vis[cur] = true;

            for(int i = 0; i < n; ++i)
            {
                if(!vis[i] && checkOk(cur, i))
                {
                    dfs(i);
                }
            }
        };

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                dfs(i);
                ++ans;
            }
        }

        return ans;
    }
};
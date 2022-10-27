class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        
        bool vis[300][300];
        memset(vis, 0, sizeof(vis));
        for(auto& map : mappings)
        {
            vis[map[0]][map[1]] = true;
        }

        int subSize = sub.size();
        int sSize = s.size();
        for(int j = 0; j <= sSize - subSize; ++j)
        {
            int i = 0;
            for(; i < subSize; ++i)
            {
                int k = i + j;
                if(s[k] != sub[i] && !vis[sub[i]][s[k]])
                    break;
            }
            if(i == subSize)
                return true;
        }
        return false;
    }
};
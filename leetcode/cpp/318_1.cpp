class Solution {
public:
    int maxProduct(vector<string>& words) {

        int n = words.size();
        bool visit[n][26];
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
             {
                 visit[i][words[i][j] - 'a'] = true;
             } 
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                bool ok = true;
                for (int k = 0; k < 26; ++k)
                {
                    if(visit[i][k] && visit[j][k])
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }

        return ans;

    }
};
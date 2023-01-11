// 剑指 Offer II 117. 相似的字符串

class Solution {
public:
    vector<int> edges[305];
    bool vis[305];

    bool check(const string& str1, const string& str2)
    {
        int cnt = 0;
        int dif1 = -1;
        int dif2 = -1;
        int n = str1.size();
        for(int i = 0; i < n; ++i)
        {
            if(str1[i] != str2[i])
            {
                ++cnt;
                if(cnt == 3)
                    return false;
                else if(cnt == 2)
                    dif2 = i;
                else if(cnt == 1)
                    dif1 = i;
            }
        }
        if(cnt == 1)
            return false;
        if(cnt == 0)
            return true;
        if(str1[dif1] != str2[dif2] || str2[dif1] != str1[dif2])
            return false;

        return true;
    }

    void dfs(int i)
    {
        for(int next : edges[i])
        {
            printf("next = %d\n", next);
            if(!vis[next])
            {
                vis[next] = true;
                dfs(next);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {

        memset(vis, 0, sizeof(vis));
        int n = strs.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(check(strs[i], strs[j]))
                {
                    printf("%d %d\n", i,j);
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            printf("%d\n", i);
            if(!vis[i])
            {
                vis[i] = true;
                dfs(i);
                ++ans;
            }
        }



        return ans;
    }
};
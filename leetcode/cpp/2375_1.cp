// 2375. 根据模式串构造最小数字

class Solution {
public:
    long long ans = 1000000000000;
    bool visit[10];
    void dfs(string& pattern, int depth, long long cur)
    {
        if(pattern.size() == depth)
        {
            ans = min(ans, cur);
            return ;
        }
        int pre = cur % 10;

        if(pattern[depth] == 'D')
        {
            for(int i = 1; i <= pre; ++i)
            {
                if(!visit[i])
                {
                    visit[i] = true;
                    dfs(pattern, depth + 1, cur * 10 + i);
                    visit[i] = false;
                }
            }
        }
        else
        {
            for(int i = pre; i < 10; ++i)
            {
                if(!visit[i])
                {
                    visit[i] = true;
                    dfs(pattern, depth + 1, cur * 10 + i);
                    visit[i] = false;
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        
        memset(visit, 0, sizeof(visit));
        for(int i = 1; i < 10; ++i)
        {
            visit[i] = true;
            dfs(pattern, 0, i);
            visit[i] = false;
        }

        return to_string(ans);
    }
};
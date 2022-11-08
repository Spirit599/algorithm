// 单调栈

class Solution {
public:
    string removeDuplicateLetters(string s) {

        bool vis[26];
        memset(vis, 0, sizeof(vis));
        int lastOccur[26];
        int n = s.size();
        for(int i = 0; i < n; ++i)
            lastOccur[s[i] - 'a'] = i;

        string stk;

        for(int i = 0; i < n; ++i)
        {
            if(vis[s[i] - 'a'])
                continue;
            while(!stk.empty() && stk.back() > s[i] && lastOccur[stk.back() - 'a'] > i)
            {
                vis[stk.back() - 'a'] = false;
                stk.pop_back();
            }
            stk.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }

        return stk;

    }
};
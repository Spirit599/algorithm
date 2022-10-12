// 2434. 使用机器人打印字典序最小的字符串

class Solution {
public:
    string robotWithString(string s) {
        
        int cnt[26];
        string ans;
        memset(cnt, 0, sizeof(cnt));
        for(char c : s)
            ++cnt[c - 'a'];
        stack<char> sta;
        for(char c : s)
        {
            --cnt[c - 'a'];
            int minn = 0;
            while(minn < 25 && cnt[minn] == 0)
                ++minn;
            sta.push(c);
            while(!sta.empty() && sta.top() - 'a' <= minn)
            {
                ans.push_back(sta.top());
                sta.pop();
            }
        }

        return ans;
    }
};

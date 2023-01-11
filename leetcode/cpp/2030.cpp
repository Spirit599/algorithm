// 单调栈

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        
        int n = s.size();
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        int c = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(s[i] == letter)
            {
                cnt[i] = ++c;
            }
            else
            {
                cnt[i] = c;
            }
        }

        int haveLetter = 0;
        string upStk;
        int need = k;
        for(int i = 0; i < n; ++i)
        {
            char c = s[i];
            while(!upStk.empty() && upStk.back() > c && n - i > need - upStk.size())
            {
                if(upStk.back() == letter && cnt[i] <= repetition - haveLetter)
                    break;

                if(upStk.back() == letter)
                    --haveLetter;
                upStk.pop_back();
            }
            if(c != letter && need - upStk.size() == repetition - haveLetter)
                continue;
            if(upStk.size() == k)
                continue;
            if(c == letter)
                ++haveLetter;
            upStk.push_back(c);

        }


        return upStk;
    }
};
//滑动窗口

class Solution {
public:
    bool equal_memo(int memoA[], int memoB[])
    {
        for (int i = 0; i < 26; ++i)
        {
            if(memoA[i] != memoB[i])
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        int memo_p[26];
        memset(memo_p, 0, sizeof(memo_p));

        int p_size = p.size();
        for (int i = 0; i < p_size; ++i)
        {
            ++memo_p[p[i] - 'a'];
        }

        int memo_subs[26];
        memset(memo_subs, 0, sizeof(memo_subs));

        int s_size = s.size();
        int i = 0;
        for (; i < min(s_size, p_size); ++i)
        {
            ++memo_subs[s[i] - 'a'];
        }

        vector<int> ans;
        if(equal_memo(memo_subs, memo_p))
            ans.push_back(0);

        int j = 0;
        for (; i < s_size; ++i,++j)
        {
            ++memo_subs[s[i] - 'a'];
            --memo_subs[s[j] - 'a'];

            if(equal_memo(memo_subs, memo_p))
                ans.push_back(j + 1);
        }

        return ans;
    }
};
//1261 · 字符至少出现K次的最长子串

class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: return an integer
     */
    const int CHAR_SIZE = 26;
    int divide(const string &s, int k, int left, int right)
    {
        int memo[CHAR_SIZE];
        memset(memo, 0, sizeof(memo));
        for(int i = left; i <= right; ++i)
            ++memo[s[i] - 'a'];

        bool split_c[CHAR_SIZE];
        memset(split_c, 0, sizeof(split_c));
        bool all_char_lower_k = true;
        bool all_char_upper_k = true;

        for(int i = 0; i < CHAR_SIZE; ++i)
        {
            if(memo[i] != 0)
            {
                if(memo[i] >= k)
                {
                    all_char_lower_k = false;
                }
                else
                {
                    all_char_upper_k = false;
                    split_c[i] = true;
                }
            }
        }

        if(all_char_lower_k)
            return 0;
        if(all_char_upper_k)
            return right - left + 1;

        int ret = 0;

        int i = left;
        while(i <= right)
        {
            if(split_c[s[i] - 'a'])
                ++i;
            else
            {
                int j = i;
                while(j <= right && !split_c[s[j] - 'a'])
                    ++j;
                ret = max(ret, divide(s, k, i, j - 1));
                i = j;
            }
        }

        return ret;
    }
    int longestSubstring(string &s, int k) {
        
        return divide(s, k, 0, s.size() - 1);
    }
};
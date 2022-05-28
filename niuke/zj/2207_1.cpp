class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        char c0 = pattern[0];
        char c1 = pattern[1];
        int c0_num = 0;
        int c1_num = 0;

        for(char c : text)
        {
            if(c == c0)
            {
                ++c0_num;
            }
            else if(c == c1)
            {
                ++c1_num;
            }
        }

        if(c0 == c1)
        {
            return (long long)(c0_num + 1) * c0_num / 2;
        }

        long long ans = max(c0_num, c1_num);

        for(char c : text)
        {
            if(c == c0)
            {
                ans += c1_num;
            }
            else if(c == c1)
            {
                --c1_num;
            }
        }

        return ans;
    }
};
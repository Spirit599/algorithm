//kmp

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = needle.size();
        int pi[n];
        pi[0] = 0;
        for(int i = 1; i < n; ++i)
        {
            int j = pi[i - 1];
            while(j && needle[i] != needle[j])
                j = pi[j - 1];
            if(needle[i] == needle[j])
                ++j;
            pi[i] = j;
        }


        int m = haystack.size();
        int mIdx = -1;
        for(int i = 0; i < m; ++i)
        {
            while(mIdx >= 0 && haystack[i] != needle[mIdx + 1])
            {
                mIdx = pi[mIdx] - 1;
            }
            if(haystack[i] == needle[mIdx + 1])
                ++mIdx;
            if(mIdx == n - 1)
                return i - n + 1;


        }

        return -1;
    }
};
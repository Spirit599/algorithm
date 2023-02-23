class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int memo[200];
        memset(memo, 0, sizeof(memo));
        int n = s.size();
        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; ++right)
        {
            char c = s[right];
            ++memo[c];

            while(memo[c] != 1)
            {
                --memo[s[left++]];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;


    }
};
class Solution {
public:
    /**
     * @param s: input string
     * @return: a string as the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        int max_len = 0;
        int s_len = s.size();
        string ans;

        for(int i = 0; i < s_len; ++i)
        {
            int left = i;
            int right = i;

            while(left - 1 >= 0 && s[left - 1] == s[i])
                --left;
            while(right + 1 < s_len && s[right + 1] == s[i])
                ++right;
            while(left - 1 >= 0 && right + 1 < s_len &&
                s[left - 1] == s[right + 1])
            {
                --left;
                ++right;
            }

            if(right - left + 1 > max_len)
            {
                max_len = right - left + 1;
                ans = s.substr(left, max_len);
            }
        }

        return ans;
    }
};
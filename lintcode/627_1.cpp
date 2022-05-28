class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        
        unordered_map<char, int> memo;

        for(char c : s)
            ++memo[c];

        int ans = 0;
        int mid = 0;

        for(auto& kav : memo)
        {
            if(kav.second & 1)
            {
                mid = 1;
                ans += kav.second - 1;
            }
            else
            {
                ans += kav.second;
            }
        }

        return ans + mid;
    }
};
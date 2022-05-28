class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> memo;

        int right = -1;
        int left = -1;
        int n = s.size();
        int ans = 0;

        while(right < n - 1)
        {
            if(right + 1 < n && memo.count(s[right + 1]) == 0)
            {
                ++right;
                memo.insert(s[right]);
            }
            else
            {
                ++left;
                memo.erase(s[left]);
            }
            ans = max(ans, right - left);
        }

        return ans;
    }
};
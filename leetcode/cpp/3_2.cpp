//3. 无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int pre_index[300];
        memset(pre_index, -1, sizeof(pre_index));

        int right = -1;
        int left = -1;
        int ans = 0;
        int n = s.size();

        while(right < n - 1)
        {

            if(right + 1 < n && pre_index[s[right + 1]] <= left)
            {
                ++right;
                pre_index[s[right]] = right;
            }
            else
            {
                left = pre_index[s[right + 1]];
            }
            ans = max(ans, right - left);
        }

        return ans;
    }
};
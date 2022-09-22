// 2414. 最长的字母序连续子字符串的长度

class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int left = -1;
        int right = -1;
        int ans = 0;
        int cur = 0;
        char pre = 0;
        int n = s.size();

        while(right + 1 < n) 
        {

            if(!cur || s[right + 1] == pre + 1) 
            {
                ++right;
                ++cur;
                pre = s[right];
                ans = max(ans, cur);
            }
            else
            {
                cur = 0;
            }
        }

        return ans;
    }
};
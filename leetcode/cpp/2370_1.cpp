// 2370. 最长理想子序列

class Solution {
public:
    int longestIdealString(string s, int k) {
        
        int leftMax[26];
        memset(leftMax, 0, sizeof(leftMax));
        int ans = 0;
        for(char c : s) {
            int index = c - 'a';
            int maxx = 0;
            for(int i = max(index - k, 0); i <= min(index + k, 25); ++i) {
                maxx = max(maxx, leftMax[i]);
            }
            int cur = maxx + 1;
            leftMax[index] = max(leftMax[index], cur);
            ans = max(ans, cur);
        }

        return ans;
    }
};
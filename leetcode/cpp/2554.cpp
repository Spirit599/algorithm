class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        sort(banned.begin(), banned.end());
        // banned.erase(unique(banned.begin(), banned.end()), banned.end());
        int idx = 0;
        int m = banned.size();
        int cur = 0;
        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(idx >= m || banned[idx] != i)
            {
                if(cur + i <= maxSum)
                {
                    cur = cur + i;
                    ++ans;
                }
                else
                {
                    return ans;
                }
            }
            else
            {
                ++idx;
            }
        }

        return ans;
    }
};
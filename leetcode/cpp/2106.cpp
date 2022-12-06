class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        int curSum = 0;
        int left = 0;
        int n = fruits.size();
        int ans = 0;

        for(int right = 0; right < n; ++right)
        {
            int rdiff = abs(startPos - fruits[right][0]);
            curSum += fruits[right][1];
            while(left <= right && min(rdiff, abs(startPos - fruits[left][0])) + fruits[right][0] - fruits[left][0] > k)
            {
                curSum -= fruits[left++][1];
            }

            ans = max(ans, curSum);
        }

        return ans;

    }
};
//149 · 买卖股票的最佳时机

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        
        int ans = 0;
        int minn = 0x7fffffff;

        int n = prices.size();
        for(int i = 0; i < n; ++i)
        {
            minn = min(minn, prices[i]);
            ans = max(ans, prices[i] - minn);
        }

        return ans;

    }
};
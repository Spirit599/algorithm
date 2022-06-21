// 151 · 买卖股票的最佳时机 III

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    void full_pre(vector<int> &prices, int pre[])
    {
        int ans = 0;
        int minn = 0x7fffffff;
        int n = prices.size();
        for(int i = 0; i < n; ++i)
        {
            minn = min(minn, prices[i]);
            ans = max(ans, prices[i] - minn);
            pre[i] = ans;
            cout<<ans<<endl;
        }
    }
    void  full_suf(vector<int>& prices, int suf[])
    {
        int ans = 0;
        int maxx = -0x7fffffff;
        int n = prices.size();
        for(int i = n - 1; i >= 0; --i)
        {
            maxx = max(maxx, prices[i]);
            ans = max(ans, maxx - prices[i]);
            suf[i] = ans;
        }
    }
    int maxProfit(vector<int> &prices) {
        
        int n = prices.size();
        int pre[n];
        full_pre(prices, pre);
        int suf[n];
        full_suf(prices, suf);

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            ans = max(ans, pre[i] + suf[i]);
        }

        return ans;

    }
};
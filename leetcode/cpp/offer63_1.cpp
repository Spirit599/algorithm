class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if(n == 0)
            return 0;

        int ans = 0;
        int maxx = prices[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            ans = max(ans, maxx - prices[i]);
            maxx = max(maxx, prices[i]);
        }
        return ans;
    }
};
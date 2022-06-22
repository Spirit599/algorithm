// 1852 · 最终优惠价

class Solution {
public:
    /**
     * @param prices: a list of integer
     * @return: return the actual prices
     */
    vector<int> finalDiscountedPrice(vector<int> &prices) {
        
        int n = prices.size();
        vector<int> ans(n);
        stack<int> sta;

        for(int i = n - 1; i >= 0; --i)
        {
            while(!sta.empty() && sta.top() > prices[i])
            {
                sta.pop();
            }
            int k = prices[i];
            if(!sta.empty())
                k = k - sta.top();
            ans[i] = k;
            sta.push(prices[i]);
        }

        return ans;
    }
};
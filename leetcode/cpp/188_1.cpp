// 188. 买卖股票的最佳时机 IV

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

    	int n = prices.size();
    	k = min(k , n / 2);
    	if(k == 0)
    		return 0;


    	int buy[k];
    	int sell[k];
    	memset(buy, 0, sizeof(buy));
    	memset(sell, 0, sizeof(sell));

    	for(int i = 0; i < k; ++i)
    		buy[i] = -prices[0];

    	for(int i = 1; i < n; ++i)
    	{
    		buy[0] = max(buy[0], -prices[i]);
    		sell[0] = max(sell[0], buy[0] + prices[i]);
    		for(int j = 1; j < k; ++j)
    		{
    			buy[j] = max(buy[j], sell[j - 1] - prices[i]);
    			sell[j] = max(sell[j], buy[j] + prices[i]);
    		}
    	}

    	return sell[k - 1];
    }
};
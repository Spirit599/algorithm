// 150 · 买卖股票的最佳时机 II

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        
        int ans = 0;
        int maxx = 0;
        int minn = 0x7fffffff;

        for(int num : prices)
        {
        	if(num > minn)
        	{
        		ans += num - minn;
        		minn = num;
        	}
        	else
        	{
        		minn = min(minn, num);
        	}
        	cout<<ans<<endl;
        }

        return ans;
    }
};
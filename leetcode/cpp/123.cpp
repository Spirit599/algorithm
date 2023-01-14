class Solution {
public:
    int maxProfit(vector<int>& prices) {

    	int b1 = -prices[0];
    	int s1 = 0;
    	int b2 = -prices[0];
    	int s2 = 0;
    	int ans = 0;

    	for(int cost : prices)
    	{
    		b1 = max(b1, -cost);
    		s1 = max(s1, b1 + cost);
    		b2 = max(b2, s1 - cost);
    		s2 = max(s2, b2 + cost);
    	}

    	return s2;
    }
};
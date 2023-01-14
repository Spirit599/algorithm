class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

		int own[k + 1];
		int unown[k + 1];
		memset(unown, 0, sizeof(unown));
		for(int i = 0; i <= k; ++i)
			own[i] = -prices[0];

		for(int cost : prices)
		{
			for(int i = 1; i <= k; ++i)
			{

				own[i] = max(own[i], unown[i - 1] - cost);
				unown[i] = max(unown[i], own[i] + cost);
			}
		}

		return unown[k];

    }
};
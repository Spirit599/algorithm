class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        
        int n = stockPrices.size();
        if(n == 2)
            return 1;
        else if(n == 1)
            return 0;

        sort(stockPrices.begin(), stockPrices.end());

        int ans = 1;
        for(int i = 1; i + 1 < n; ++i)
        {
            ans += check(stockPrices[i - 1][0], stockPrices[i][0], stockPrices[i + 1][0],
                        stockPrices[i - 1][1], stockPrices[i][1], stockPrices[i + 1][1]);
        }
        return ans;
    }
    int check(long long x1, long long x2, long long x3,
                long long y1, long long y2, long long y3)
    {
        if((y3 - y1) * (x2 - x1) == (y2 - y1) * (x3 - x1))
            return 0;
        return 1;
    }
};
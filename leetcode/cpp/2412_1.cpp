// 贪心
// 2412. 完成所有交易的初始最少钱数

class Solution {
public:

    long long minimumMoney(vector<vector<int>>& transactions) {
        
        long long total = 0; 
        int maxx = 0;
        int n = transactions.size();

        for(int i = 0; i < n; ++i) {

            total += max(transactions[i][0] - transactions[i][1], 0);
            maxx = max(maxx, min(transactions[i][0], transactions[i][1]));
        }

        return total + maxx;
    }
};
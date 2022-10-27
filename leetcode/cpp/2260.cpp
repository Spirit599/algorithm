class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int, int> memo;
        int n = cards.size();
        int ans = n + 1;
        for(int i = 0; i < n; ++i)
        {
            if(memo.count(cards[i]) == 1)
            {
                ans = min(ans, i - memo[cards[i]] + 1);
            }
            memo[cards[i]] = i;
        }
        if(ans != n + 1)
            return ans;
        else
            return -1;
    }
};
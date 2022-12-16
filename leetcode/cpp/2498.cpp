class Solution {
public:
    int maxJump(vector<int>& stones) {
        
        int n = stones.size();

        int ans = stones[1] - stones[0];
        for(int i = 0; i + 2 < n; ++i)
        {
            ans = max(ans, stones[i + 2] - stones[i]);
        }

        return ans;


    }
};
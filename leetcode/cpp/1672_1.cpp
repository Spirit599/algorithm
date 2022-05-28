class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int ans = 0;
        for(auto& vec : accounts)
        {
            int sum = accumulate(vec.begin(), vec.end(), 0);
            ans = max(ans, sum);
        }
        return ans;
    }
};
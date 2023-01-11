class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int ans = INT_MIN;
        int n = values.size();
        int cur = values[n - 1] - (n - 1);
        

        for(int i = n - 2; i >= 0; --i)
        {
            ans = max(ans, values[i] + i + cur);
            cur = max(cur, values[i] - i);
        }
        return ans;
    }
};
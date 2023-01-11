class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        int diff[n + 1];
        memset(diff, 0, sizeof(diff));

        for(auto& booking : bookings)
        {
            diff[booking[0] - 1] += booking[2];
            diff[booking[1]] -= booking[2];
        }

        vector<int> ans(n);
        int pre = 0;
        for(int i = 0; i < n; ++i)
        {
            pre += diff[i];
            ans[i] = pre;
        }

        return ans;
    }
};
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        int a = costs[0][0];
        int b = costs[0][1];
        int c = costs[0][2];
        int n = costs.size();
        for(int i = 1; i < n; ++i)
        {
            int na = INT_MAX;
            int nb = INT_MAX;
            int nc = INT_MAX;
            na = min(b, c) + costs[i][0];
            nb = min(a, c) + costs[i][1];
            nc = min(b, a) + costs[i][2];
            a = na;
            b = nb;
            c = nc;
        }
        return min({a, b, c});
    }
};
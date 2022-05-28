class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        
        vector<int> yy[101];

        for(auto& vec : rectangles)
            yy[vec[1]].emplace_back(vec[0]);

        for(auto& y : yy)
            sort(y.begin(), y.end());

        int n = points.size();
        vector<int> ans(n);

        for(int i = 0; i < n; ++i)
        {
            for(int y = points[i][1]; y <= 100; ++y)
            {
                auto& v = yy[y];
                ans[i] += v.end() - lower_bound(v.begin(), v.end(), points[i][0]);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end());

        int right = points[0][1];
        int ans = 1;
        int n = points.size();

        for(int i = 1; i < n; ++i)
        {
            // printf("%d\n", right);
            auto& point = points[i];
            if(point[0] > right)
            {
                ++ans;
                right = point[1];
            }
            else
            {
                right = min(right, point[1]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        nth_element(points.begin(), points.begin() + k - 1, points.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] * v1[0] + v1[1] * v1[1] < v2[0] * v2[0] + v2[1] * v2[1];
        });
        points.resize(k);
        return points;
    }
};
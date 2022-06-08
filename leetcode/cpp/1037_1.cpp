class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {

        pair<int, int> p1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        pair<int, int> p2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return p1.first * p2.second - p1.second * p2.first != 0;
    }
};
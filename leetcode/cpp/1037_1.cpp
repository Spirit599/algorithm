class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {

        pair<int, int> p1 = {points1][0] - points0][0], points1][1] - points0][1]};
        pair<int, int> p2 = {points2][0] - points0][0], points2][1] - points0][1]};
        return p1.first * p2.second - p1.second * p2.first != 0;
    }
};
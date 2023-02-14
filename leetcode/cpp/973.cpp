class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] * v1[0] + v1[1] * v1[1] > v2[0] * v2[0] + v2[1] * v2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(points.begin(), points.end() ,cmp);
        vector<vector<int>> ans;
        while(k--)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
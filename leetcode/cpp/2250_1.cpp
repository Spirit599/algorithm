//

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        
        sort(rectangles.begin(), rectangles.end(), [](auto& v1, auto& v2) { return v1[1] > v2[1]; });

        int n = points.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) { return points[i][1] > points[j][1]; });

        vector<int> ans(n);
        vector<int> vec;
        int i = 0;

        for(int index : ids)
        {
            int start = i;
            while(i < rectangles.size() && rectangles[i][1] >= points[index][1])
                vec.emplace_back(rectangles[i++][0]);
            if(start != i)
                sort(vec.begin(), vec.end());

            ans[index] = vec.end() - lower_bound(vec.begin(), vec.end(), points[index][0]);
        }

        return ans;
    }
};
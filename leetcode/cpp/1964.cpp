class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> upVec;

        for(int i = 0; i < n; ++i)
        {
            int v = obstacles[i];
            auto it = upper_bound(upVec.begin(), upVec.end(), v);
            if(it == upVec.end())
            {
                upVec.emplace_back(v);
                ans[i] = upVec.size();
            }
            else
            {
                *it = v;
                ans[i] = it - upVec.begin() + 1;
            }
        }

        return ans;
    }
};
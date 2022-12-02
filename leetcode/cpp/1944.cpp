class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        int n = heights.size();
        vector<int> ans(n);
        vector<int> downStk;

        for(int i = n - 1; i >= 0; --i)
        {
            int num = 0;
            while(!downStk.empty() && heights[downStk.back()] < heights[i])
            {
                ++num;
                downStk.pop_back();
            }
            if(!downStk.empty())
                ++num;
            ans[i] = num;
            downStk.push_back(i);

        }

        return ans;
    }
};
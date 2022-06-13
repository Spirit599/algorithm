class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int ans = 0;
        vector<int> heights_copy(heights);

        sort(heights_copy.begin(), heights_copy.end());

        for(int i = 0; i < heights.size(); ++i)
            ans += (heights_copy[i] != heights[i]);

        return ans;
    }
};
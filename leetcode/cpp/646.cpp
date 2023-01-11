class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end());
        int ans = 1;
        int right = pairs[0][1];
        int n = pairs.size();
        
        for(int i = 1; i < n; ++i)
        {
            if(pairs[i][0] > right)
            {
                ++ans;
                right = pairs[i][1];
            }
            else
            {
                right = min(right, pairs[i][1]);
            }
        }
        return ans;
    }
};
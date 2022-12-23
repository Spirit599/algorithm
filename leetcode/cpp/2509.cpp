class Solution {
public:
    int getSteps(int x, int y)
    {
        int steps = 0;
        while(x != y)
        {
            if(x > y)
            {
                x = x >> 1;
                ++steps;
            }
            else
            {
                y = y >> 1;
                ++steps;
            }
        }
        return steps;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        

        vector<int> ans;
        for(auto& query : queries)
        {
            ans.emplace_back(getSteps(query[0], query[1]) + 1);
        }
        return ans;
    }
};
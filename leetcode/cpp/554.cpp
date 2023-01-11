class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {


        unordered_map<int, int> memo;

        for(auto& vec : wall)
        {
            int n = vec.size();
            int preSum = 0;
            for(int i = 0; i < n; ++i)
            {
                preSum += vec[i];
                vec[i] = preSum;
                ++memo[vec[i]];
            }
        }

        int width = wall[0][wall[0].size() - 1];
        int maxx = 0;
        for(auto& kv : memo)
        {
            if(kv.first != width)
                maxx = max(maxx, kv.second);
        }

        return wall.size() - maxx;
    }
};
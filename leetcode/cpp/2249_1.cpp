class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        
        set<pair<int, int>> memo;
        int ans = 0;

        for(auto& vec : circles)
        {
            int min_x = vec[0] - vec[2];
            int max_x = vec[0] + vec[2];
            int min_y = vec[1] - vec[2];
            int max_y = vec[1] + vec[2];

            for(int x = min_x; x <= max_x; ++x)
            {
                for(int y = min_y; y <= max_y; ++y)
                {
                    if(memo.count({x, y}) == 1)
                        continue;

                    double dis = (sqrt((x - vec[0]) * (x - vec[0]) + (y - vec[1]) * (y - vec[1])));

                    if(dis < vec[2] || fabs(dis - vec[2]) < 1e-6)
                    {
                        ++ans;
                        memo.insert({x, y});
                    }
                }
            }
        }

        return ans;
    }
};
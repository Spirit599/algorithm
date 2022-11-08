double eps = 0.0000001;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {

        sort(towers.begin(), towers.end());
        int n = towers.size();
        int maxEnergy = -1;
        vector<int> ans;

        for(int x = 0; x <= 50; ++x)
        {
            for(int y = 0; y <= 50; ++y)
            {
                int allEnergy = 0;
                for(int j = 0; j < n; ++j)
                {
                    int dx = towers[i][0] - x;
                    int dy = towers[i][1] - y;
                    double dis = sqrt(dx * dx + dy * dy);
                    if(dis > radius + eps)
                        continue;
                    printf("%d, %lf\n", towers[j][2], dis + 1);
                    int energy = floor(towers[j][2] / (dis + 1));
                    printf("%d\n", energy);
                    allEnergy += energy;
                }
                if(allEnergy > maxEnergy)
                {
                    maxEnergy = allEnergy;
                    ans = {x, y};
                }
            }
        }

        return ans;
    }
};
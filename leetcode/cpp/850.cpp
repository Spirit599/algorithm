// 扫描线

struct xInfo {
    int x;
    int low;
    int high;
    int dif;
};
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {

        int n = rectangles.size();
        int mod = 1e9 + 7;

        vector<int> yy;
        vector<xInfo> xx;
        for(auto& rect : rectangles)
        {
            yy.emplace_back(rect[1]);
            yy.emplace_back(rect[3]);
            xx.push_back({rect[0], rect[1], rect[3], 1});
            xx.push_back({rect[2], rect[1], rect[3], -1});
        }

        //去重
        sort(yy.begin(), yy.end());
        yy.erase(unique(yy.begin(), yy.end()), yy.end());
        int ySize = yy.size();
        int cnt[ySize];
        memset(cnt, 0, sizeof(cnt));

        sort(xx.begin(), xx.end(), [](const xInfo& x1, const xInfo& x2) {return x1.x < x2.x;});

        long long ans = 0;
        int xSize = xx.size();
        for(int i = 0; i < xSize - 1; ++i)
        {
            long long y = 0;
            for(int j = 0; j < ySize - 1; ++j)
            {
                if(xx[i].low <= yy[j] && yy[j + 1] <= xx[i].high)
                    cnt[j] += xx[i].dif;

                if(cnt[j] > 0)
                {
                    y += (yy[j + 1] - yy[j]);
                }
            }

            ans += y * (xx[i + 1].x - xx[i].x);
        }

        return ans % mod;
    }
};
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int ret = 0;

        for(int i = 0; i < n; ++i)
        {
            int base = 1;
            int cur = 0;
            for(int j = i; j < n; ++j)
            {
                cur += satisfaction[j] * base;
                ++base;
                ret = max(ret, cur);
            }
            // printf("%d\n", cur);
        }

        return ret;
    }
};
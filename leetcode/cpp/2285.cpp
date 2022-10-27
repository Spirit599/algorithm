class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        int degress[n];
        memset(degress, 0, sizeof(degress));
        for(auto& road : roads)
        {
            ++degress[road[0]];
            ++degress[road[1]];
        }
        sort(degress, degress + n);
        long long ans = 0;
        for(int i = 1; i <= n; ++i)
            ans += 1ll * degress[i - 1] * i;
        return ans;
    }
};
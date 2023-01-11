class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {

        int v = destination[0];
        int h = destination[1];
        int n = h + v;
        
        long long comb[n + 1][n + 1];
        memset(comb, 0, sizeof(comb));
        comb[0][0] = 1;
        for(int i = 1; i <= n; ++i)
        {
            comb[i][0] = 1;
            for(int j = 1; j <= i; ++j)
            {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }

        string ans;
        for(int i = 0; i < n; ++i)
        {
            if(h)
            {
                int cnt = comb[h + v - 1][h - 1];
                if(k > cnt)
                {
                    ans.push_back('V');
                    k -= cnt;
                    --v;
                }
                else
                {
                    ans.push_back('H');
                    --h;
                }
            }
            else
            {
                ans.push_back('V');
                --v;
            }
        }

        return ans;
    }
};
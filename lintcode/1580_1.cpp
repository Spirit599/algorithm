// 1850 · 捡苹果

class Solution {
public:
    /**
     * @param a: a list of integer
     * @param k: a integer
     * @param l: a integer
     * @return: return the maximum number of apples that they can collect.
     */
    int pickApples(vector<int> &a, int k, int l) {
        

        int ans = pick(a, k, l);
        reverse(a.begin(), a.end());
        ans = max(ans, pick(a, k, l));
        return ans;
    }

    int pick(vector<int> &a, int k, int l)
    {
        int n = a.size();
        if(n < k + l)
            return -1;

        int pre_sum[n];
        int sum = 0;
        memset(pre_sum, 0, sizeof(pre_sum));
        for(int i = 0; i < n; ++i)
        {
            sum += a[i];
            pre_sum[i] = sum;
        }

        int dp1[n];
        memset(dp1, 0, sizeof(dp1));
        int maxx = 0;
        for(int i = k - 1; i <= n - 1; ++i)
        {
            maxx = max(maxx, pre_sum[i] - pre_sum[i - k + 1] + a[i - k + 1]);
            dp1[i] = maxx;
        }

        int dp2[n];
        memset(dp2, 0, sizeof(dp2));
        maxx = 0;
        for(int i = n - l; i >= 0; --i)
        {
            maxx = max(maxx, pre_sum[i + l - 1] - pre_sum[i] + a[i]);
            dp2[i] = maxx;
            
        }

        int ans = 0;
        for(int i = 0; i + 1 < n; ++i)
        {
            //cout<<i<<" "<<dp1[i]<<" "<<dp2[i + 1]<<endl;
            ans = max(ans , dp1[i] + dp2[i + 1]);
        }

        return ans;
    }
};
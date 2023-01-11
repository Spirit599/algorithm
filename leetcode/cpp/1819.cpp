class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {

        int maxn = *max_element(nums.begin(), nums.end());

        int vis[maxn + 1];
        memset(vis, 0, sizeof(vis));
        for(int x : nums)
        {
            for(int i = 1; i * i <= x; ++i)
            {
                if(x % i == 0)
                {
                    int j = x / i;
                    if(!vis[i])
                        vis[i] = x;
                    else
                        vis[i] = gcd(vis[i], x);

                    if(i != j)
                    {
                        if(!vis[j])
                            vis[j] = x;
                        else
                            vis[j] = gcd(vis[j], x);
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= maxn; ++i)
            if(vis[i] == i)
                ++ans;
        return ans;
    }
};
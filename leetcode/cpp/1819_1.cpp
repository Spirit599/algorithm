class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {

        int maxn = *max_element(nums.begin(), nums.end());

        int vis[maxn + 1];
        memset(vis, -1, sizeof(vis));

        for(int num : nums)
        {
            for(int i = 1; i * i <= num; ++i)
            {
                if(num % i == 0)
                {
                    if(vis[i] == -1)
                    {
                        vis[i] = num;
                    }
                    else
                    {
                        vis[i] = gcd(num, vis[i]);
                    }
                    int j = num / i;
                    if(i == j)
                        continue;
                    if(vis[j] == -1)
                        vis[j] = num;
                    else
                    {
                        vis[j] = gcd(num, vis[j]);
                    }

                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= maxn; ++i)
        {
            if(vis[i] == i)
                ++ans;
        }        

        return ans;
    }
};
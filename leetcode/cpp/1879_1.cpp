//状态压缩dp
//动态规划

class Solution {
public:
    int weight(int num)
    {
        int ans = 0;
        while(num)
        {
            ans += num & 1;
            num = num >> 1;
        }
        return ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int S_size = 1 << n;
        int dp[S_size];
        memset(dp, 0x3f, sizeof(dp));

        dp[0] = 0;

        for (int S = 0; S < S_size; ++S)
        {
            int k = weight(S);

            for (int j = 0; j < n; ++j)
            {
                if(!(1 << j & S))
                {
                    //cout<<nums1[k]<<" "<<nums2[j]<<" "<<dp[S]<<endl;
                    dp[1 << j | S] = min(dp[1 << j | S], dp[S] + (nums1[k] ^ nums2[j]));
                    //cout<<(1<<j)<<" "<<S<<" "<<(1 << j | S)<<" "<<dp[1 << j | S]<<endl;
                }
            }
        }

        return dp[S_size - 1];
    }
};
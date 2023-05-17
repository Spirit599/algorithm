class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        
        int n2 = arr2.size();
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int inf = 0x3f3f3f3f;

        arr1.insert(arr1.begin(), -1);
        arr1.push_back(inf);
        int n1 = arr1.size();

        int dp[n1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;

        for(int i = 1; i < n1; ++i)
        {
            int k = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            for(int j = 1; j <= min(i - 1, k); ++j)
            {
                if(arr1[i - j - 1] < arr2[k - j])
                {
                    dp[i] = min(dp[i], dp[i - j - 1] + j);
                }
            }

            if(arr1[i - 1] < arr1[i]) 
            {
                dp[i] = min(dp[i], dp[i - 1]);
            }
        }

        return dp[n1 - 1] != inf ? dp[n1 - 1] : -1;
    }
};
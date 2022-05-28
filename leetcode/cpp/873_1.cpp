class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        long long ret = 0; 

        unordered_map<int, int> hash;
        int arr_size = arr.size();
        for(int i = 0; i < arr_size; ++i)
        {
            hash[arr[i]] = i;
        }

        int dp[arr_size][arr_size];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < arr_size; ++i)
        {
            for (int j = i + 1; j < arr_size; ++j)
            {
                auto it = hash.find(arr[j] - arr[i]);
                if(it != hash.end())
                {
                    if(it->second < i)
                    {
                        dp[i][j] = dp[it->second][i] + 1;
                        if(dp[i][j] > ret)
                        {
                            ret = dp[i][j];
                        }
                    }
                }
            }
        }

        if(ret)
            return ret + 2;
        else
            return 0;
    }
};
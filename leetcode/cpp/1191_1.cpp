//子序列最大和
//环形子序列最大和


const int MOD = 1000000007;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        long long single_max = 0;
        long long single_min = 0;
        long long cur_max = 0;
        long long cur_min = 0;
        long long sum = 0;

        int n = arr.size();

        for (int i = 0; i < n; ++i)
        {
            if(cur_max + arr[i] >= 0)
            {
                cur_max += arr[i];
                single_max = max(single_max, cur_max);
            }
            else
            {
                cur_max = 0;
            }
            if(cur_min + arr[i] <= 0)
            {
                cur_min += arr[i];
                single_min = min(single_min, cur_min);
            }
            else
            {
                cur_min = 0;
            }
            sum += arr[i];
        }

        long long prefix_min = 0;
        long long presum = 0;
        for (int i = 0; i < n; ++i)
        {
            presum += arr[i];
            prefix_min = min(prefix_min, presum);
        }

        long long suffix_min = 0;
        long long sufsum = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            sufsum += arr[i];
            suffix_min = min(suffix_min, sufsum);
        }

        if(k == 1)
            return single_max % MOD;
        else
        {
            if(sum > 0)
            {
                return ((k * sum) - suffix_min - prefix_min) % MOD;
            }
            else if(sum <= 0)
            {
                return max(single_max, (sum - single_min)) % MOD;
            }
        }

        return 0;
    }
};
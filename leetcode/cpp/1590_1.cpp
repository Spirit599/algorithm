//前缀和
//hash

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int n = nums.size();

        long long presum[n];
        presum[0] = nums[0];

        for (int i = 1; i < n; ++i)
        {
            presum[i] = presum[i - 1] + nums[i];
        }

        int remainder = presum[n - 1] % p;

        if(remainder == 0)
            return 0;

        unordered_map<int, int> um;
        um[0] = -1;

        int ans = n;
        for (int i = 0; i < n; ++i)
        {
            int cur_mod = presum[i] % p;
            int key = (cur_mod - remainder + p) % p;
            cout<<cur_mod<<" "<<key<<endl;
            if(um.count(key) == 1)
                ans = min(ans, i - um[key]);
            um[cur_mod] = i;

        }

        if(ans != n)
            return ans;
        else
            return -1;
    }
};
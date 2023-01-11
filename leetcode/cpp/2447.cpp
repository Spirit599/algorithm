class Solution {
public:
    int gcd(int n, int m) {
        while(n != 0) {
            int r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
    int subarrayGCD(vector<int>& nums, int k) {
        
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int preGcd = nums[i];
            if(preGcd == k)
                ++ans;
            for(int j = i + 1; j < n; ++j)
            {
                preGcd = gcd(preGcd, nums[j]);
                if(preGcd == k)
                    ++ans;
                else if(preGcd > k && preGcd % k)
                    break;
            }
        }


        return ans;
    }
};
class Solution {
public:
    int gcd(int m, int n)
    {
        while(m)
        {
            int r = n % m;
            n = m;
            m = r;
        }
        return n;
    }
    int lcm(int m, int n)
    {
        return m * n / gcd(m, n);
    }
    int subarrayLCM(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int pre = 1;
            for(int j = i; j < n; ++j)
            {
                pre = lcm(pre, nums[j]);
                if(pre == k)
                    ++ans;
                if(pre > k)
                    break;
            }
        }
        return ans;
    }
};
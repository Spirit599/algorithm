class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {


        long long ans = 0;
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int& num : nums)
            num = __builtin_popcount(num);
        sort(nums.begin(), nums.end());

        for(int num : nums)
        {
            if(num + num >= k)
                ++ans;
        }

        int n = nums.size();
        int ll = 0;
        int rr = n - 1;
        while(rr != ll)
        {
            if(nums[rr] + nums[ll] >= k)
            {
                ans += 2 * (rr - ll);
                --rr;
            }
            else
            {
                ++ll;
            }
        }

        return ans;
    }
};
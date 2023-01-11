class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int rr = k;
        int ll = k;
        int n = nums.size();
        int ans = 0;
        for(int i = nums[k]; i > 0; --i)
        {
            while(rr < n && nums[rr] >= i) ++rr;
            while(ll >= 0 && nums[ll] >= i) --ll;
            printf("%d %d %d \n", i,ll,rr);
            ans = max(ans, (rr - ll - 1) * i);
        }
        return ans;
    }
};
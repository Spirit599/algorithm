class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        set<long long> memo;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            auto it = memo.lower_bound(0ll + nums[i] - t);
            if(it != memo.end() && *it <= 0ll + nums[i] + t)
                return true;
            memo.insert(nums[i]);
            if(i >= k)
                memo.erase(nums[i - k]);
        }
        return false;
    }
};
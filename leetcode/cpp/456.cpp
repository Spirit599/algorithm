class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size();
        int preMin[n];
        preMin[0] = nums[0];
        for(int i = 1; i < n; ++i)
        {
            preMin[i] = min(preMin[i - 1], nums[i]);
        }

        set<int> memo;
        for(int i = n - 1; i >= 1; --i)
        {
            int high = nums[i];
            int low = preMin[i - 1];
            if(high <= low)
                continue;
            auto it = memo.upper_bound(low);
            if(it != memo.end() && *it < high)
                return true;
            memo.insert(high);
        }

        return false;
    }
};
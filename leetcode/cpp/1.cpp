typedef pair<int, int> pii;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<pii> numsAndIdx(n);

        for(int i = 0; i < n; ++i)
            numsAndIdx[i] = make_pair(nums[i], i);

        sort(numsAndIdx.begin(), numsAndIdx.end());
        int ll = 0;
        int rr = nums.size() - 1;

        while(ll != rr)
        {
            int v = numsAndIdx[ll].first + numsAndIdx[rr].first;
            if(v < target)
                ++ll;
            else if(v > target)
                --rr;
            else
                return {numsAndIdx[ll].second, numsAndIdx[rr].second};
        }

        return {};
    }
};
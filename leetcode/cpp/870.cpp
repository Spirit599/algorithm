class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {

        multiset <int> memo(nums1.begin(), nums1.end());
        
        int n = nums2.size();
        vector<int> ans(n);

        for(int i = 0; i < n; ++i)
        {
            auto it = memo.upper_bound(nums2[i]);
            if(it == memo.end())
                it = memo.begin();
            ans[i] = *it;
            memo.erase(it);
        }

        return ans;
    }
};
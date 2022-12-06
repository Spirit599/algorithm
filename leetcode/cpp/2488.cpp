class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int ans = 0;
        int n = nums.size();

        int mid = -1;

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == k)
            {
                mid = i;
            }
        }

        if(mid == -1)
            return 0;

        int dif = 0;
        unordered_map<int, int> pre;

        for(int i = mid; i >= 0; --i)
        {
            if(nums[i] > k)
                ++dif;
            else if(nums[i] < k)
                --dif;

            ++pre[dif];
        }

        dif = 0;
        unordered_map<int, int> suf;
        for(int i = mid; i < n; ++i)
        {
            if(nums[i] > k)
                ++dif;
            else if(nums[i] < k)
                --dif;
            ++suf[dif];
        }

        for(auto& kv : pre)
        {
            int key = kv.first;
            auto it = suf.find(-key);
            if(it != suf.end())
                ans += kv.second * it->second;

            auto it1 = suf.find(1 - key);
            if(it1 != suf.end())
                ans += kv.second * it1->second;
        }



        return ans;
    }
};
//532. 数组中的 k-diff 数对

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        if(k != 0)
        {
            set<int> strip(nums.begin(), nums.end());
            vector<int> arr(strip.begin(), strip.end());
            int ans = 0;

            int left = 0;
            int right = 0;
            int n = arr.size();

            while(right < n)
            {

                int cur = arr[right] - arr[left];
                if(cur < k)
                    ++right;
                else if(cur > k)
                    ++left;
                else
                {
                    ++ans;
                    ++right;
                }
            }
            return ans;
        }
        else
        {
            unordered_map<int, int> memo;
            for(int num : nums)
                ++memo[num];
            int ans = 0;
            for(auto& kav : memo)
                if(kav.second > 1)
                    ++ans;
            return ans;
        }
    }
};
// 二分 凹函数

class Solution {
public:
    long long compute(vector<int>& nums, vector<int>& cost, int mid) {

        long long ret = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            ret += 1ll * abs(nums[i] - mid) * cost[i];
        }
        return ret;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int low = 0;
        int high = 1000000;

        while(low != high) 
        {
            int mid = (low + high) >> 1;
            if(compute(nums, cost, mid) > compute(nums, cost, mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        return compute(nums, cost, low);

    }
};
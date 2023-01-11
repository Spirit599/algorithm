//334. 递增的三元子序列
//贪心

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();
        if(n < 3)
            return false;

        int n1 = nums[0];
        int n2 = INT_MAX;

        for(int i = 1; i < n; ++i)
        {
            int num = nums[i];
            if(num > n2)
                return true;
            else if(num > n1)
                n2 = num;
            else
                n1 = num;
        }

        return false;
    }
};
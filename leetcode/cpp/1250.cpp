class Solution {
public:
    bool isGoodArray(vector<int>& nums) {

        int g = nums[0];
        for(int num : nums)
            g = gcd(g, num);
        return g == 1;
    }
};
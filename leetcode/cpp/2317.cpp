class Solution {
public:
    int maximumXOR(vector<int>& nums) {

        int ans = 0;
        for(int num : nums)
        {
            ans = ans | num;
        }
        return ans;
    }
};
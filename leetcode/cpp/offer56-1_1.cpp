//分组异或

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {

        int xor_sum = 0;

        for(int num : nums)
        {
            xor_sum ^= num;
        }

        int bits = 1;
        while((bits & xor_sum) == 0)
            bits <<= 1;

        int a = 0;
        int b = 0;
        for(int num : nums)
        {
            if(bits & num)
                a ^= num;
            else
                b ^= num;
        }

        return vector<int>{a, b};
    }
};
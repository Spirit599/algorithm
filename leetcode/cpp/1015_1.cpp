class Solution {
public:
    int smallestRepunitDivByK(int k) {

        if((k & 1) == 0 || k % 5 == 0)
            return -1;

        int ans = 1;
        int remainder = 0;
        while(true)
        {
            remainder = (remainder * 10 + 1) % k;
            if(remainder == 0)
                break;
            ++ans;
        }

        return ans;
    }
};
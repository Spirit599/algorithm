//829. 连续整数求和
class Solution {
public:
    int consecutiveNumbersSum(int n) {

        int upper_limit = 2 * n;
        int ans = 0;
        for(int i = 1; i * (i + 1) <= upper_limit; ++i)
        {
            ans += judge(n, i);
        }

        return ans;
    }
    int judge(int n, int i)
    {
        if(i & 1)
            return n % i == 0;
        else
            return (n % i != 0) && (2 * n % i == 0);
    }
};
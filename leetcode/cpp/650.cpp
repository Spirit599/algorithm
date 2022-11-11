class Solution {
public:
    int minSteps(int n) {

        if(n == 1)
            return 0;

        int ret = INT_MAX;
        for(int i = n - 1; i >= 1; --i)
        {
            if(n % i == 0)
            {
                ret = min(ret, minSteps(i) + n / i);
                break;
            }
        }
        return ret;

    }
};
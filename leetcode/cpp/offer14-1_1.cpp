class Solution {
public:
    int cuttingRope(int n) {

        long long ans = 1;

        if(n == 2)
            return 1;
        else if(n == 3)
            return 2;
        else if(n == 4)
            return 4;
        else
        {
            while(n > 4)
            {
                n = n - 3;
                ans *= 3;
            }
        }
        return ans * n;
    }
};
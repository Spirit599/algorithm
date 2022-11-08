class Solution {
public:
    int helper(int n) {
        if(n <= 4)
            return n;
        else
            return helper(n - 3) * 3;
    }
    int integerBreak(int n) {

        if(n <= 3)
            return n - 1;
        else if(n == 4)
            return 4;
        else
            return helper(n);
    }
};
class Solution {
public:
    bool checkPowersOfThree(int n) {

        return helper(n, true);
    }

    bool helper(int n, bool subOne) {

        if(n == 0)
            return true;
        if(n % 3 == 0)
            return helper(n / 3, true);
        if(n % 3 == 1 && subOne)
            return helper(n - 1, false);
        else
            return false;
    }
};
class Solution {
public:
    int lastRemaining(int n) {

        if(n == 1)
            return 1;
        // else if(n & 1)
        //     return 2 * lastRemaining(n >> 1);
        else
            return 2 * ((n >> 1) + 1 - lastRemaining(n >> 1));
    }
};
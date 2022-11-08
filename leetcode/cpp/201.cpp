class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        int dif = right - left;
        int ans = 0;
        int bit = 30;

        while(bit != -1 && (1 << bit) - 1 >= dif)
        {
            printf("%d\n", (1 << bit) - 1);
            if(((left & right) >> bit) & 1)
                ans += (1 << bit);
            --bit;
        }
        return ans;
    }
};
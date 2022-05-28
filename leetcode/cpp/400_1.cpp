class Solution {
public:
    int findNthDigit(int n) {

        long long maxx = 9;
        long long bits = 1;
        long long nums = 9;
        long long k = 9;

        while(maxx < n)
        {
            ++bits;
            nums = nums * 10;
            maxx = maxx + bits * nums;
            k = 9 + 10 * k;
        }



        long long a = k - (maxx - n) / bits;
        long long b = (maxx - n) % bits;

        while(b)
        {
            --b;
            a = a / 10;
        }

        return a % 10;
    }
};
class Solution {
public:
    int reverse(int num) {
        int k = 0;
        while(num) {
            k = 10 * k + num % 10;
            num = num / 10;
        }
        return k;
    }
    bool sumOfNumberAndReverse(int num) {
        
        for(int i = 0; i <= num; ++i)
        {
            if(i + reverse(i) == num)
                return true;
        }
        return false;
    }
};
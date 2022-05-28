class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        
        int ans = 0;

        while(number)
        {
            ans = 10 * ans + number % 10;
            number /= 10;
        }

        return ans;
    }
};
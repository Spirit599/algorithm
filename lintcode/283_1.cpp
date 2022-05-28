class Solution {
public:
    /**
     * @param num1: An integer
     * @param num2: An integer
     * @param num3: An integer
     * @return: an interger
     */
    int maxOfThreeNumbers(int num1, int num2, int num3) {
        
        return max(max(num1, num2), num3);
    }
};
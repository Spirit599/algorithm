// 394 · 硬币排成线

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        
        return (n % 3) != 0;
    }
};
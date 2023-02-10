class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        
        int g = gcd(targetX, targetY);
        return __builtin_popcount(g) == 1;
    }
};
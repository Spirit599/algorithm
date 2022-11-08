
class Solution {
public:
    int gcd(int x, int y)
    {
        while(x)
        {
            int r = y % x;
            y = x;
            x = r;
        }
        return y;
    }
    bool canMeasureWater(int x, int y, int z) {

        return x + y >= z && z % gcd(x, y) == 0;
    }
};
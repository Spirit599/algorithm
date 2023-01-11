class Solution {
public:
    bool judgeSquareSum(int c) {

        int sq = sqrt(c);
        for(int i = 1; i <= sq; ++i)
        {
            int bb = c - i * i;
            double sqb = sqrt(bb);
            if(int(sqb) == sqb)
                return true;
        }
        return false;
    }
};
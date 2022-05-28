//加法

class Solution {
public:
    int add(int a, int b) {

        while(b)
        {
            int c = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = c;
        }

        return a;
    }
};
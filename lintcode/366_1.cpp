class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        
        if(n == 0)
            return 0;
        else if(n == 1)
            return 0;

        int p1 = 0;
        int p2 = 1;

        

        while(n != 2)
        {
            int tmp = p2;
            p2 = p2 + p1;
            p1 = tmp;
            --n;
        }

        return p2;
    }
};
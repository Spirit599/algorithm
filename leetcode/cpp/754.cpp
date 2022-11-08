class Solution {
public:
    int reachNumber(int target) {

        long long n = 1;
        target = abs(target);

        while(n * (n + 1) < 2ll * target)
            ++n;

        long long dif = n * (n + 1) / 2 - target;
        
        while((dif & 1))
        {
            ++n;
            dif = n * (n + 1) / 2 - target;
        }
        return n;
    }
};
class Solution {
public:
    int flipLights(int n, int presses) {

        n = min(4, n);
        int onOff = 16;
        unordered_set<int> memo;
        for(int s = 0; s < onOff; ++s)
        {
            int sum = __builtin_popcount(s);

            if(sum > presses || (sum % 2 != presses % 2))
                continue;
            
            printf("s = %d\n", s);
            int status = 0;
            if(s & 1)
            {
                status ^= 1;
                status ^= 2;
                status ^= 4;
                status ^= 8;
            }
            if((s >> 1) & 1)
            {
                status ^= 1;
                status ^= 4;
            }
            if((s >> 2) & 1)
            {
                status ^= 2;
                status ^= 8;
            }
            if((s >> 3) & 1)
            {
                status ^= 1;
                status ^= 8;
            }
            status = ((1 << n) - 1) & status;
            printf("%d\n", status);
            memo.insert(status);
        }

        return memo.size();
    }
};
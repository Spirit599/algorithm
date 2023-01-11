class Solution {
public:
    int numberOfWays(string corridor) {
        
        int num = 0;
        for(char c : corridor)
            if(c == 'S')
                ++num;
        if(num == 0 || num & 1)
            return 0;

        long long ans = 1;
        int mod = 1e9 + 7;
        int base = 0;
        num = 0;
        for(char c : corridor)
        {
            if(c == 'S')
            {
                ++num;
                if(num == 3)
                {
                    num = 1;
                    ans = (ans * base) % mod;
                    base = 0;
                }
                else if(num == 2)
                {
                    base = 1;
                }
            }
            else
            {
                if(num == 2)
                {
                    ++base;
                }
            }
        }

        return ans;
    }
};
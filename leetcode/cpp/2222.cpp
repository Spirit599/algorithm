class Solution {
public:
    long long numberOfWays(string s) {
        
        long long ans = 0;
        int n = s.size();
        long long n1 = 0;
        long long n2 = 0;
        long long n3 = 0;
        long long n4 = 0;
        long long n5 = 0;
        long long n6 = 0;

        for(char c : s)
        {
            if(c == '0')
            {
                n3 += n2;
                ++n1;

                n5 += n4;
            }
            else
            {
                n2 += n1;

                ++n4;
                n6 += n5;
            }
        }
        printf("%d %d\n", n3,n6);
        return n3 + n6;

    }
};
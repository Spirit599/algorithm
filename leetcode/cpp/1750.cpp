class Solution {
public:
    int minimumLength(string s) {

        int n = s.size();

        int ll = 0;
        int rr = n - 1;
        while(ll < rr)
        {
            if(s[ll] != s[rr])
                break;
            while(ll != rr && s[ll + 1] == s[ll])
                ++ll;
            while(ll != rr && s[rr - 1] == s[rr])
                --rr;
            ++ll;
            --rr;
            // printf("%d %d\n", ll,rr);
        }

        return max(rr - ll + 1, 0);
    }
};
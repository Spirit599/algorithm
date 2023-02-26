class Solution {
public:
    int minimumSwap(string s1, string s2) {

        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 != n2)
            return -1;
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        int xMatch = 0;
        int yMatch = 0;

        for(int i = 0; i < n1; ++i)
        {
            if(s1[i] == 'x')
            {
                ++x1;
                if(s2[i] == 'x')
                {
                    ++xMatch;
                    ++x2;
                }
                else
                {
                    ++y2;
                }
            }
            else if(s1[i] == 'y')
            {
                ++y1;
                if(s2[i] == 'y')
                {
                    ++yMatch;
                    ++y2;
                }
                else
                {
                    ++x2;
                }
            }
        }

        if((x1 + x2) & 1)
            return -1;
        x1 -= xMatch;
        y1 -= yMatch;

        int ans = x1 / 2 + x1 % 2 + y1 / 2 + x1 % 2;

        return ans;
    }
};
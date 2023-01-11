class Solution {
public:
    int largestVariance(string s) {
        
        int ans = 0;
        int n = s.size();
        for(char x = 'a'; x <= 'z'; ++x)
        {
            for(char y = 'a'; y <= 'z'; ++y)
            {
                if(x == y)
                    continue;
                int diff = 0;
                int diffWithY = -n;
                for(char c : s)
                {
                    if(c == x)
                    {
                        ++diff;
                        ++diffWithY;
                    }
                    else if(c == y)
                    {
                        diffWithY = --diff;
                        diff = max(diff, 0);
                    }
                    ans = max(ans, diffWithY);
                }

                
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        int a = 0;
        int b = 0;
        for(char c : s)
        {
            if(c == '1')
                ++a;
        }
        for(char c : target)
        {
            if(c == '1')
                ++b;
        }

        return ((a == 0) && (b == 0)) || ((a > 0) && (b > 0));

    }
};
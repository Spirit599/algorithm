//734 · 形式为a^i b^j c^k的子序列数量

class Solution {
public:
    /**
     * @param source: the input string
     * @return: the number of subsequences 
     */
    int countSubsequences(string &source) {
        
        int ans = 0;
        int a = 0;
        int b = 0;
        int c = 0;

        for(char ch : source)
        {
            if(ch == 'a')
            {
                a = 2 * a + 1;
            }
            else if(ch == 'b')
            {
                b = 2 * b;
                b += a;
            }
            else if(ch == 'c')
            {
                c = 2 * c;
                c += b;
            }
            //cout<<a<<" "<<b<<" "<<c<<endl;
        }

        return c;
    }
};
//位运算

class Solution {
public:
    bool isUnique(string astr) {

        int mask = 0;
        for(char ch : astr)
        {
            cout<<mask<<endl;
            if(mask & (1 << (ch - 'a')))
            {
                return false;
            }
            else
            {
                mask = mask | (1 << (ch - 'a'));
            }
        }

        return true;
    }
};
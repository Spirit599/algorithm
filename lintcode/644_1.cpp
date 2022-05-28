class Solution {
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        
        int n = num.size();
        for(int i = 0; i <= n / 2; ++i)
        {
            if(num[i] == '1' && num[n - i - 1] == '1')
            {
                ;
            }
            else if(num[i] == '8' && num[n - i - 1] == '8')
            {
                ;
            }
            else if(num[i] == '6' && num[n - i - 1] == '9')
            {
                ;
            }
            else if(num[i] == '9' && num[n - i - 1] == '6')
            {
                ;
            }
            else if(num[i] == '0' && num[n - i - 1] == '0')
            {
                ;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
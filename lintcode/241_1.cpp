class Solution {
public:
    /**
     * @param target: A string
     * @return: An integer
     */
    int stringToInteger(string &target) {
        
        long long ans = 0;

        int n = target.size();

        if(target[0] == '-')
        {
            for(int i = 1; i < n; ++i)
                ans = 10 * ans + target[i] - '0';

            ans *= -1;
        }
        else
        {
            for(int i = 0; i < n; ++i)
                ans = 10 * ans + target[i] - '0';
        }

        return ans;
    }
};
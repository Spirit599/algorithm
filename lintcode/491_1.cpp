class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        
        string num_str(to_string(num));

        int n = num_str.size();
        for(int i = 0; i < n / 2; ++i)
        {
            if(num_str[i] != num_str[n - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};
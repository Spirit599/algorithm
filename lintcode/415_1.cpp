//415 · 有效回文串

class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        
        string str;
        for(char c : s)
        {
            if(isdigit(c) || islower(c))
                str.push_back(c);
            else if(isupper(c))
                str.push_back(c - 'A' + 'a');
        }

        return check_palindrome(str);
    }

    bool check_palindrome(const string& str)
    {
       int n = str.size();
       for (int i = 0; i < n / 2; ++i)
       {
            if(str[i] != str[n - i - 1])
                return false;
       }
       return true;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {

        string ret;
        int s_size = s.size();
        int max_length = 0;
        for (int i = 0; i < s_size; ++i)
        {
            int left = i;
            int right = i;
            while(left - 1 >= 0 && s[left - 1] == s[i])
                left--;
            while(right + 1 < s_size && s[right + 1] == s[i])
                right++;
            while(left - 1 >= 0 && right + 1 < s_size &&
                s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }
            if(right - left + 1> max_length)
            {
                max_length = right - left + 1;
                ret = s.substr(left, right - left + 1);
            }

        }
        return ret;
    }
};
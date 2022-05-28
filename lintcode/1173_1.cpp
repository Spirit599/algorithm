//字符串

class Solution {
public:
    /**
     * @param s: a string
     * @return: reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order
     */
    string reverseWords(string &s) {
        // Write your code here

        auto p_cur = s.begin();


        while(p_cur != s.end())
        {

            while(p_cur != s.end() && *p_cur == ' ')
                ++p_cur;

            auto p_left = p_cur;
            auto p_right = p_cur;

            while(p_right != s.end() && *p_right != ' ')
                ++p_right;

            reverse(p_left, p_right);

            p_cur = p_right;

        }

        return s;
    }
};
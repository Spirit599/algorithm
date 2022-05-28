class Solution {
public:
    void Pretreatment(string &s)
    {
        string temp;
        for(char &c: s)
        {
            if((c >= '0' && c <= '9')
                ||(c >= 'a' && c <= 'z'))
            {
                temp += c;
            }
            else if(c >= 'A' && c <= 'Z')
            {
                c = c - 'A' + 'a';
                temp += c;
            }
        }

        s = temp;
    }
    bool isPalindrome(string s) {

        Pretreatment(s);

        string scopy = s;

        reverse(s.begin(), s.end());
        
        return scopy == s;
    }
};
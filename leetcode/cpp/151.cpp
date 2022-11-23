class Solution {
public:
    string reverseWords(string s) {

        string ans;
        reverse(s.begin(), s.end());
        istringstream istr(s);
        string str;

        while(istr >> str)
        {
            reverse(str.begin(), str.end());
            ans += (str + " ");
        }
        ans.pop_back();
        return ans;
    }
};
class Solution {
public:
    string replaceSpace(string s) {

        string ans;
        for(char ch : s)
        {
            if(ch != ' ')
                ans.push_back(ch);
            else
                ans += "%20";
        }
        return ans;
    }
};
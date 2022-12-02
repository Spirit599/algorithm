class Solution {
public:
    string makeLargestSpecial(string s) {

        vector<string> vt;
        int n = s.size();
        int cur = 0;
        int left = 0;

        for(int i = 0; i < n; ++i)
        {
            cur += (s[i] == '1') ? 1 : -1;
            if(cur == 0)
            {
                vt.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                left = i + 1;
            }
        }

        sort(vt.begin(), vt.end(), greater<string>());
        return accumulate(vt.begin(), vt.end(), string(""));
    }
};
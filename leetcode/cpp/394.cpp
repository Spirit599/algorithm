class Solution {
public:
    string decodeString(string s) {

        vector<int> numStk;
        vector<string> strStk;
        string ans;

        int i = 0;
        int n = s.size();
        int num = 0;
        while(i < n)
        {
            if(isdigit(s[i]))
            {
                
                while(i < n && isdigit(s[i]))
                {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                --i;

            }
            else if(isalpha(s[i]))
            {
                ans.push_back(s[i]);
            }
            else if(s[i] == '[')
            {
                if(num == 0)
                    num = 1;
                numStk.emplace_back(num);
                strStk.emplace_back(ans);
                num = 0;
                ans = "";

            }
            else
            {
                int k = numStk.back();
                string ll = strStk.back();
                string addStr(ans);
                for(int i = 1; i < k; ++i)
                    addStr += ans;
                numStk.pop_back();
                strStk.pop_back();
                ans = ll + addStr;
            }
            ++i;
        }

        return ans;
    }
};
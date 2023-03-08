class Solution {
public:
    string decodeString(string s) {

        vector<string> strStk{""};
        vector<int> numStk;

        int num = 0;
        // string cur;

        for(char c : s)
        {
            if(isdigit(c))
            {
                num = 10 * num + c - '0';
            }
            else if(isalpha(c))
            {
                strStk.back().push_back(c);
            }
            else if(c == '[')
            {
                numStk.push_back(num);
                strStk.push_back("");
                num = 0;
            }
            else
            {
                string last = strStk.back();
                string tmp;
                strStk.pop_back();
                int k = numStk.back();
                numStk.pop_back();
                if(k == 0)
                    k = 1;
                while(k--)
                    tmp += last;
                strStk.back().append(tmp);
            }
        }

        return strStk.back();
    }
};
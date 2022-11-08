class Solution {
public:
    vector<string> getNum(string s) {
        
        vector<string> ret;
        if(s[0] != '0' || s == "0")
            ret.push_back(s);
        if(s.back() == '0')
            return ret;
        int n = s.size();
        for(int i = 1; i < n; ++i)
        {
            if(s[0] == '0' && i != 1)
                continue;
            ret.push_back(s.substr(0, i) + "." + s.substr(i));
        }
        return ret;
    }
    vector<string> ambiguousCoordinates(string s) {

        s = s.substr(1, s.size() - 2);
        int n = s.size();

        vector<string> ret;
        for(int i = 1; i < n; ++i)
        {
            vector<string> getNum1 = getNum(s.substr(0, i));
            if(getNum1.empty())
                continue;
            vector<string> getNum2 = getNum(s.substr(i));
            if(getNum2.empty())
                continue;
            for(string& num1 : getNum1)
            {
                for(string& num2 : getNum2)
                {
                    ret.push_back("(" + num1 + ", " + num2 + ")");
                }
            }
        }

        return ret;
    }
};
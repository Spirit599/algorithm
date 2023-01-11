class Solution {
public:
    bool areNumbersAscending(string s) {
        
        istringstream istream(s);
        string str;
        int pre = -1;
        while(istream >> str)
        {
            if(isdigit(str[0]))
            {
                int num = stoi(str);
                if(num <= pre)
                    return false;
                pre = num;
            }
        }

        return true;
    }
};
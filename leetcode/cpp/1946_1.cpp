class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {

        bool start = false; 
        for (int i = 0; i < num.size(); ++i)
        {
 
            if(start && (num[i] - '0') > change[num[i] - '0'])
                break;

            if(change[num[i] - '0'] > (num[i] - '0'))
            {
                num[i] = change[num[i] - '0'] + '0';
                start = true;
            }
        }

        return num;
    }
};
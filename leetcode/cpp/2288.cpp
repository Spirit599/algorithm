class Solution {
public:
    string discountPrices(string sentence, int discount) {
        
        istringstream istream(sentence);
        string ans;
        string cur;
        while(istream >> cur) 
        {
            //cout<<cur<<endl;
            bool isNum = false;
            long long num = 0;
            int n = cur.size();
            if(n > 1 && cur[0] == '$')
            {
                isNum = true;
                for(int i = 1; i < n; ++i)
                {
                    if(cur[i] >= '0' && cur[i] <= '9')
                    {
                        num = 10 * num + cur[i] - '0';
                    }
                    else
                    {
                        isNum = false;
                        break;
                    }
                }
            }
            if(isNum)
            {
                double dnum = num * (100 - discount) * 0.01;
                stringstream ss;
                ss << setiosflags(ios::fixed) << std::setprecision(2) << dnum;
                cur = "$" + ss.str();
            }
            ans += cur + " ";

        }

        ans.pop_back();
        return ans;
    }
};
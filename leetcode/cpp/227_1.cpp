// 227. 基本计算器 II


class Solution {
public:
    int get_num(int &i, int n,const string& s)
    {
        int num = 0;
        while(!isdigit(s[i]))
            ++i;
        while(i < n && isdigit(s[i]))
        {
            num = num * 10 - '0' + s[i];
            ++i;
        }
        --i;
        return num;
    }

    int calculate(string s) {

        vector<int> sta;
        int n = s.size();
        int num = 0;
        int syb = 1;
        int i = 0;
        while(i < n)
        {
            //cout<<i<<endl;

            if(isdigit(s[i]))
            {
                num = get_num(i, n, s);
            }

            if(s[i] == '*')
            {
                int num1 = get_num(i, n, s);
                num = num * num1;
            }
            else if(s[i] == '/')
            {
                int num1 = get_num(i, n, s);
                num = num / num1;
            }
            else if(s[i] == '+')
            {
                sta.push_back(num * syb);
                syb = 1;
                num = 0;
            }
            else if(s[i] == '-')
            {
                sta.push_back(num * syb);
                syb = -1;
                num = 0;
            }

            ++i;
            if(i == n)
            {
                sta.push_back(num * syb);
            }
        }


        return accumulate(sta.begin(), sta.end(), 0);
    }
};
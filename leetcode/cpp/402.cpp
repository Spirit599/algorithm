// 单调栈

class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();
        if(k >= n)
            return "0";

        int need = n - k;
        string stk;
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && stk.back() > num[i] && need - stk.size() < n - i)
                stk.pop_back();
            if(stk.size() != need)
                stk.push_back(num[i]);
        }

        int Numindex = -1;
        for(int i = 0; i < need; ++i)
        {
            if(stk[i] != '0')
            {
                Numindex = i;
                break;
            }
        }

        if(Numindex != -1)
            return stk.substr(Numindex);
        else
            return "0";
    }
};
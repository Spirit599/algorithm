// stack 栈
// 括号 解压


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串
     */
    string compress(string str) {
        // write code here
        string ret;

        stack<int> nums;
        stack<string> tmpstr;

        string tmp;
        int num = 0;

        for(auto c : str)
        {
            if(isalpha(c))
            {
                tmp += c;
            }
            else if(isdigit(c))
            {
                num = 10 * num + c - '0';
            }
            else if(c == '[')
            {
                nums.push(num);
                tmpstr.push(tmp);
                num = 0;
                tmp = "";
            }
            else if(c == ']')
            {
                string kk;
                if(num == 0)
                    kk = tmp;
                for(int i = 1; i <= num; ++i)
                    kk += tmp;

                tmp = tmpstr.top() + kk;
                num = nums.top();
                tmpstr.pop();
                nums.pop();
            }
        }

        return tmp;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution sol;
//     cout<<sol.compress("HG[2|QWE[2|QWE]JXY]")<<endl;
//     return 0;
// }

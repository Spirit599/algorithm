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
    struct Node {
        string str;
        int num;
    };
    stack<Node> st;
    string compress(string str) {
        // write code here
        int i = 0; 
        string t = "";
        int num = 0; 
        while (str[i]) {
            if (str[i] >= '0' && str[i] <= '9') {
                num = num*10 + (str[i] - '0');
            } else if (str[i] == '[') {
                st.push({t, num});
                t = "";
                num = 0;
            } else if (str[i] == ']') {
                string t2 = "";
                if (num == 0) t2 = t;
                for (int i = 0; i < num; i++) {
                    t2 += t;
                }
                t = st.top().str + t2;
                num = st.top().num;
                st.pop();
            } else if (str[i] != '|') {
                t += str[i];
            }
            // cout << t << endl;
            i++;
        }
        return t;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.compress("[2|QWE][2|JXY]")<<endl;
    return 0;
}

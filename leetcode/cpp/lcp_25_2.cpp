//组合数学 重集的组合 本题是排列
//母函数 


#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    int keyboard(int k, int n) {

        long long ans[n + 1];
        memset(ans, 0, sizeof(ans));
        long long polynomial[k + 1];
        memset(polynomial, 0, sizeof(polynomial));
        long long tmp[n + 1];
        memset(tmp, 0, sizeof(tmp));

        for (int i = 0; i <= k; ++i)
        {
            polynomial[i] = 1;
            ans[i] = 1;
        }

        for (int i = 0; i < 25; ++i)
        {
            memset(tmp, 0, sizeof(tmp));
            for (int j = 0; j <= k; ++j)
            {
                for (int l = 0; l <= n; ++l)
                {
                    if(j + l <= n)
                    {
                        //cout<<j<<l<<" "<<ans[j + l]<<endl;
                        tmp[j + l] += polynomial[j] * ans[l]; 
                    }
                }
            }
            memcpy(ans, tmp, sizeof(tmp));
            for (int l = 0; l <= n; ++l)
            {
                cout<<ans[l]<<" ";
            }
            cout<<endl;
        }

        return ans[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution().keyboard(2, 2);
    return 0;
}

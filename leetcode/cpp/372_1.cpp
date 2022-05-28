const int MOD = 1337;

class Solution {
public:
    void sub_2(vector<int>& b)
    {
        int n = b.size();
        int bit = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int tmp = (b[i] + bit) / 2;
            if(b[i] & 1)
            {
                bit = 10;
            }
            else
            {
                bit = 0;
            }
            b[i] = tmp;
        }
        if(b.back() == 0)
            b.pop_back();
    }
    int superPow(int a, vector<int>& b) {

        long long ans = 1;

        a = a % MOD;

        reverse(b.begin(), b.end());

        while(!b.empty())
        {
            int n = b.size();
            if(b[0] & 1)
            {
                --b[0];
                ans = ans * a % MOD;
            }
            sub_2(b);
            a = a * a % MOD;
            // for (int i = 0; i < b.size(); ++i)
            // {
            //     cout<<b[i]<<" ";
            // }
            // cout<<endl;
        }

        return ans;
    }
};
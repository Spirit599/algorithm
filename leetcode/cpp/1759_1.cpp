const int MOD = 1000000007;

class Solution {
public:
    int countHomogenous(string s) {

        long long ans = 0;
        long long num = 0;
        char pre_char = '#';

        for (int i = 0; i < s.size(); ++i)
        {
            //cout<<num<<endl;
            if(s[i] != pre_char)
            {
                ans += (num * (num + 1) / 2) % MOD;
                num = 1;
                pre_char = s[i];
                //cout<<ans<<endl;
            }
            else
            {
                ++num;
            }
        }
        //cout<<(num * (num + 1) / 2) % MOD<<endl;
        ans += (num * (num + 1) / 2) % MOD;

        return ans;
    }
};
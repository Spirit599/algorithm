class Solution {
public:
    string compressString(string S) {

        if(S == "")
            return "";

        string ans;
        int n = S.size();

        int num = 1;
        int prev_ch = S[0];
        for (int i = 1; i < n; ++i)
        {
            if(S[i] == prev_ch)
            {
                ++num;
            }
            else
            {
                ans.push_back(prev_ch);
                ans += to_string(num);
                prev_ch = S[i];
                num = 1;

            }
        }
        ans.push_back(prev_ch);
        ans += to_string(num);

        if(ans.size() < n)
            return ans;
        else
            return S;

    }
};
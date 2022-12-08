class Solution {
public:
    string minWindow(string s, string t) {

        int ll = -1;
        int rr = -1;
        int inf = 0x3f3f3f3f;
        int minLength = inf;

        unordered_map<char, int> memo;
        for(char c : t)
            ++memo[c];

        auto checkOk = [&]() -> bool {

            for(auto& kv : memo)
                if(kv.second > 0)
                    return false;
            return true;
        };

        int left = 0;
        int n = s.size();
        for(int right = 0; right < n; ++right)
        {
            if(memo.count(s[right]))
                --memo[s[right]];
            while(checkOk())
            {
                int curLen = (right - left + 1);
                if(curLen < minLength)
                {
                    minLength = curLen;
                    rr = right;
                    ll = left;
                }
                if(memo.count(s[left]))
                    ++memo[s[left]];
                ++left;
            }
        }

        if(minLength != inf)
            return s.substr(ll, minLength);
        return "";
    }
};
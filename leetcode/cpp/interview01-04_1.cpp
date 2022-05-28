class Solution {
public:
    bool canPermutePalindrome(string s) {

        unordered_map<char, int> memo;
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            ++memo[s[i]];
        }

        bool mid = false;
        if(n & 1)
            mid = true;

        for(auto kav : memo)
        {
            cout<<kav.first<<" "<<kav.second<<endl;
            if(kav.second & 1)
            {
                if(mid)
                {
                    mid = false;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};
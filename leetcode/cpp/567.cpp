class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int memo[26];
        memset(memo, 0, sizeof(memo));
        for(char c : s1)
            ++memo[c - 'a'];


        function<int()> check = [&]() -> int {

            bool hasNum = false;
            for(int i = 0; i < 26; ++i)
            {
                if(memo[i] < 0)
                    return -1;
                else if(memo[i] > 0)
                    hasNum = true;
            }
            return hasNum;
        };

        int left = 0;
        int n = s2.size();
        for(int right = 0; right < n; ++right)
        {
            --memo[s2[right] - 'a'];
            while(check() < 0)
            {
                ++memo[s2[left++] - 'a'];
            }
            if(check() == 0)
                return true;
        }
        return false;
    }

};
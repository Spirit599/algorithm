// 1375 · 至少K个不同字符的子串

class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
    
    long long kDistinctCharacters(string &s, int k) {
    
        int n = s.size();
        if(n < k)
            return 0;

        long long ans = 0;
        unordered_map<int, int> memo;

        int left = -1;
        int right = -1;

        while(right < n)
        {
            if(memo.size() < k)
            {
                ++right;
                ++memo[s[right]];
            }
            else
            {
                ans += n - right;
                ++left;
                if(--memo[s[left]] == 0)
                    memo.erase(s[left]);
            }
        }

        return ans;
    }
};
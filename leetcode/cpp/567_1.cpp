class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(char c : s1)
        {
            ++cnt[c - 'a'];
        }
        int cur = 0;
        for(int i = 0; i < 26; ++i)
            if(cnt[i] != 0)
                ++cur;
        
        int n2 = s2.size();
        int left = 0;
        for(int right = 0; right < n2; ++right)
        {
            int k = --cnt[s2[right] - 'a'];
            if(k == 0)
                --cur;
            if(k == -1)
            {
                while(s2[left] != s2[right])
                {
                    int z = ++cnt[s2[left++] - 'a'];
                    if(z == 1)
                        ++cur;
                }
                ++cnt[s2[left++] - 'a'];
            }

            if(cur == 0)
                return true;
        }
        return false;
    }

};
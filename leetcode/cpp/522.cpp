class Solution {
public:
    bool s1IsSubstrOfS2(const string& s1, const string& s2) {

        int m = s1.size();
        int n = s2.size();
        int ptr2 = 0;
        for(int ptr1 = 0; ptr1 < m; ++ptr1)
        {
            if(m - ptr1 > n - ptr2)
                return false;

            while(ptr2 < n && s1[ptr1] != s2[ptr2])
                ++ptr2;
            if(ptr2 == n)
                return false;
            ++ptr2;
        }
        return true;

    }
    int findLUSlength(vector<string>& strs) {

        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
            return s1.size() > s2.size();
        });

        int n = strs.size();
        int ans = -1;
        for(int i = 0; i < n; ++i)
        {
            bool ok = true;
            for(int j = 0; j < n; ++j)
            {
                if(i == j)
                    continue;
                if(s1IsSubstrOfS2(strs[i], strs[j]))
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                ans = strs[i].size();
                break;
            }
        }


        return ans;
        
    }
};
class Solution {
public:
    string customSortString(string order, string s) {

        int priority[26];
        memset(priority, 0x3f, sizeof(priority));
        int n = order.size();
        for(int i = 0; i < n; ++i)
            priority[order[i] - 'a'] = i;

        sort(s.begin(), s.end(), [&](const char& c1, const char& c2)
            {return priority[c1 - 'a'] < priority[c2 - 'a']});

        return s;
    }
};
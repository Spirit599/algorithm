class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int start[26];
        memset(start, -1, sizeof(start));
        int end[26];
        memset(end, -1, sizeof(end));
        int n = s.size();

        for(int i = 0; i < n; ++i)
        {
            end[s[i] - 'a'] = i;
            if(start[s[i] - 'a'] == -1)
                start[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;
        for(int i = 0; i < 26; ++i)
        {
            if(start[i] != -1)
            {
                intervals.emplace_back(end[i], start[i]);
            }
        }

        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int preEnd = -1;
        for(auto& p : intervals)
        {
            auto [e, b] = p;
            int idx = e;

            while(idx > b)
            {
                if(end[s[idx] - 'a'] > e)
                    break;
                b = min(b, start[s[idx] - 'a']);
                if(b <= preEnd)
                    break;
                --idx;
            }
            if(idx == b)
            {
                ans.push_back(s.substr(b, e - b + 1));
                preEnd = e;
            }
        }

        return ans;
    }
};
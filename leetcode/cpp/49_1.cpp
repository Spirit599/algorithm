class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ret;

        vector<string> copystrs = strs;

        int strs_len = strs.size();

        for (int i = 0; i < strs_len; ++i)
        {
            sort(copystrs[i].begin(), copystrs[i].end());
        }

        bool visit[strs_len];
        memset(visit, 0, sizeof(visit));

        int i = 0;
        while(i < strs_len)
        {
            if(visit[i])
            {
                i++;
                continue;
            }
            vector<string> temp;
            temp.push_back(strs[i]);
            int j = i + 1;
            while(j < strs_len)
            {
                if(visit[j])
                {
                    j++;
                    continue;
                }
                if(copystrs[i] == copystrs[j])
                {
                    temp.push_back(strs[j]);
                    visit[j] = 1;
                }
                j++;
            }
            ret.push_back(temp);
            i++;
        }

        return ret;
    }
};
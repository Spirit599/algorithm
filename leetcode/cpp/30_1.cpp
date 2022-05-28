//字符串 子串
//hash
//滑动窗口

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string, int> um;
        for(string word : words)
            ++um[word];

        int s_size = s.size();
        int single_length = words[0].size();
        int words_nums = words.size();

        vector<int> ans;
        for (int i = 0; i < single_length; ++i)
        {
            if(i + words_nums * single_length > s_size)
                continue;

            unordered_map<string, int> cur;
            for (int j = 0; j < words_nums; ++j)
            {
                ++cur[s.substr(i + j * single_length, single_length)];
            }
            if(cur == um)
                ans.push_back(i);

            for (int l = i + single_length * words_nums; l + single_length <= s_size; l += single_length)
            {

                string add = s.substr(l, single_length);
                string sub = s.substr(l - single_length * words_nums, single_length);
                ++cur[add];
                --cur[sub];
                if(cur[sub] == 0)
                    cur.erase(sub);
                if(cur == um)
                    ans.push_back(l - single_length * words_nums + single_length);
            }
        }

        return ans;
    }
};
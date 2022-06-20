// 32 · 最小子串覆盖

class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    unordered_map<char, int> source_memo;
    unordered_map<char, int> target_memo;
    string minWindow(string &source, string &target) {

        if(target == "")
            return source;
        
        for(char c : target)
            ++target_memo[c];

        int left = -1;
        int right = -1;
        int n = source.size();
        int minn = n + 5;
        int right_index = -1;
        int left_index = -1;

        while(right < n)
        {
            //cout<<right<<" "<<left<<endl;
            if(check())
            {
                if(right - left < minn)
                {
                    minn = right - left;
                    right_index = right;
                    left_index = left;
                }

                ++left;
                --source_memo[source[left]];
            }
            else
            {
                ++right;
                ++source_memo[source[right]];
            }
        }

        if(right_index == -1)
            return "";
        else
            return source.substr(left_index + 1, right_index - left_index);
    }

    bool check()
    {
        for(auto& kav : target_memo)
        {
            auto it = source_memo.find(kav.first);
            if(it == source_memo.end())
                return false;
            if((*it).second < kav.second)
                return false;
        }

        return true;
    }
};
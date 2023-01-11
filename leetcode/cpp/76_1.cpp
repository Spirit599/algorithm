// 76. 最小覆盖子串

class Solution {
public:
    unordered_map<char, int> check_list;
    string minWindow(string s, string t) {

        
        //unordered_set<char> active_list;

        for(char c : t)
            ++check_list[c];
        // for(auto& kav : check_list)
        //     active_list.insert(kav.first);

        int left = -1;
        int right = -1;

        int n = s.size();
        int minn = 0x7fffffff;
        string ans;
        while(right < n)
        {
            if(check())
            {
                if(right - left < minn)
                {
                    minn = right - left;
                    cout<<minn<<endl;
                    ans = s.substr(left + 1, right - left);
                    cout<<ans<<endl;
                }
                ++left;
                auto it = check_list.find(s[left]);
                if(it != check_list.end())
                {
                    ++(it->second);
                }  
            }
            else
            {
                ++right;
                if(right == n)
                    break;
                auto it = check_list.find(s[right]);
                if(it != check_list.end())
                {
                    --(it->second);
                }
            }
        }
        return ans;
    }

    bool check()
    {
        for(auto& kav : check_list)
            if(kav.second > 0)
                return false;
        return true;
    }
};
typedef pair<int, int> pii;
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        
        const int maxn = 30;
        unordered_map<int, pii> memo;
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '0')
            {
                memo[0] = make_pair(i, i);
                break;
            }
        }
        
        for(int i = n - 1; i >= 0; --i)
        {
            int cur = 0;
            for(int len = 1; len <= maxn; ++len)
            {
                int j = i - len + 1;
                if(j < 0)
                    break;
                if(s[j] == '0')
                    continue;
                cur |= (1 << (len - 1));
                memo[cur] = make_pair(j, i);
            }
        }

        vector<vector<int>> ans;
        for(auto& query : queries)
        {
            int x = query[0] ^ query[1];
            auto it = memo.find(x);
            if(it != memo.end())
            {
                ans.push_back({it->second.first, it->second.second});
            }
            else
            {
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};
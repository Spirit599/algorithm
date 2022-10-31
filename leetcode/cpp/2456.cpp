class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        unordered_map<string, pair<long long, pair<int, string>>> memo;
        vector<vector<string>> ans;

        int n = creators.size();
        long long maxx = 0;
        for(int i = 0; i < n; ++i)
        {
            auto it = memo.find(creators[i]);
            if(it == memo.end())
            {
                memo[creators[i]] = make_pair(views[i], make_pair(views[i], ids[i]));
                maxx = max(maxx, 1ll * views[i]);
            }
            else
            {
                it->second.first += views[i];
                maxx = max(maxx, it->second.first);
                auto& _old = it->second.second;
                auto _new = make_pair(views[i], ids[i]);
                if(_new.first > _old.first)
                    _old = _new;
                else if(_new.first == _old.first && _new.second < _old.second)
                    _old = _new;
            }
        }

        for(auto& kv : memo)
        {
            if(kv.second.first == maxx)
                ans.push_back({kv.first, kv.second.second.second});
        }



        return ans;
    }
};
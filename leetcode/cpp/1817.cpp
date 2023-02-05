class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {

    	vector<int> ans(k);
    	unordered_map<int, unordered_set<int>> memo;
    	for(auto& log : logs)
    	{
    		memo[log[0]].emplace(log[1]);
    	}
    	for(auto& kv : memo)
    	{
    		++ans[kv.second.size() - 1];
    	}
    	return ans;
    }
};
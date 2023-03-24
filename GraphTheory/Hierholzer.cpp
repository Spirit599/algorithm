//欧拉回路

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> edges;
        for(auto& ticket : tickets)
            edges[ticket[0]].emplace(ticket[1]);
        
        vector<string> stk;

        function<void(string&)> dfs = [&](string& cur) -> void {

            while(edges.count(cur) && !edges[cur].empty())
            {
                string next = edges[cur].top();
                edges[cur].pop();
                dfs(next);
            }

            stk.emplace_back(cur);
        };

        string s = "JFK";
        dfs(s);
        reverse(stk.begin(), stk.end());
        return stk;
    }
};
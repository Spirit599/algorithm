// Hierholzer 算法
// 欧拉路径
class Solution {
public:

    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> edges;
    vector<string> ret;

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto& vec : tickets)
            edges[vec[0]].push(vec[1]);


        function<void(string)> dfs = [&] (string cur) {

            while(edges.count(cur) && edges[cur].size() != 0)
            {
                string next = edges[cur].top();
                edges[cur].pop();
                dfs(next);
            }

            ret.push_back(cur);
        };

        dfs("JFK");
        reverse(ret.begin(), ret.end());

        return ret;
    }
};
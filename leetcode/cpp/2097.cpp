// 欧拉路径


class Solution {
public:
    unordered_map<int, vector<int>> edges;
    unordered_map<int, int> outDegress;
    vector<int> path;
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        for(auto& vec : pairs)
        {
            edges[vec[0]].push_back(vec[1]);
            ++outDegress[vec[0]];
            --outDegress[vec[1]];
        }
        int start = -1;
        int maxx = -1;
        for(auto& kv : outDegress)
        {
            if(kv.second > maxx)
            {
                maxx = kv.second;
                start = kv.first;
            }
        }
        //printf("%d\n", start);

        function<void(int)> dfs = [&](int cur) {

            while(edges.count(cur) && edges[cur].size())
            {
                int next = edges[cur].back();
                edges[cur].pop_back();
                dfs(next);
            }
            //printf("%d\n", cur);
            path.push_back(cur);
        };

        dfs(start);
        reverse(path.begin(), path.end());
        vector<vector<int>> ret;

        int n = path.size();
        for(int i = 1; i < n; ++i)
        {
            ret.push_back({path[i - 1], path[i]});
        }


        
        return ret;


    }
};
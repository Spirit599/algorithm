// 399. 除法求值

class Solution {
public:
    struct edge
    {
        string name;
        double cost;
    };
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<edge>> edges;
        int n = equations.size();

        for(int i = 0; i < n; ++i)
        {
            edges[equations[i][0]].push_back({equations[i][1], values[i]});
            edges[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> ans;
        for(auto& vec : queries)
        {
            queue<edge> que;
            unordered_set<string> visited;
            if(edges.count(vec[0]))
            {
                que.push({vec[0], 1});
                visited.insert(vec[0]);
            }
            while(!que.empty())
            {
                edge node = que.front();
                if(node.name == vec[1])
                {
                    ans.push_back(node.cost);
                    break;
                }
                que.pop();
                for(auto& next : edges[node.name])
                {
                    if(visited.count(next.name) == 0)
                    {
                        visited.insert(next.name);
                        que.push({next.name, next.cost * node.cost});
                    }
                }
            }

            if(visited.count(vec[1]) == 0)
                ans.push_back(-1);
        }

        return ans;
    }
};
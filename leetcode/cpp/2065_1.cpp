//能用pair就用pair
//dfs
const int MAX_NODE = 1005;

class Solution {
public:
    int ans = 0;
    vector<pair<int, int>> edgess[MAX_NODE];
    void dfs(vector<int>& values, int maxTime, int cur, int cur_time, int cur_value)
    {

        //int cur = path[path.size() - 1];
        //cout<<cur<<" "<<cur_value<<" "<<cur_time<<endl;
        if(cur == 0)
                ans = max(ans, cur_value);

        for (pair<int, int> son : edgess[cur])
        {
            //vector<int> son = edgess[cur][i];
            //int time = cur_time + son[1];

            if(maxTime < cur_time + son.second)
                continue;

            int tmp_value = values[son.first];
            //int value = cur_value + tmp_value;

            values[son.first] = 0;
            //path.push_back(son.first);
            dfs(values, maxTime, son.first, cur_time + son.second, cur_value + tmp_value);
            //path.pop_back();
            values[son.first] = tmp_value;
        }
        return ;
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {

        for (int i = 0; i < edges.size(); ++i)
        {
            edgess[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            edgess[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        vector<int> path;
        path.push_back(0);//node,value,time
        int cur_value = values[0];
        values[0] = 0;
        dfs(values, maxTime, 0, 0, cur_value);
        

        return ans;
    }
};
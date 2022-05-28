//邻接表

const int MAX_NODE = 100005;

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {

        vector<int> edges[MAX_NODE];
        for (auto& vec : graph)
        {
            edges[vec[0]].push_back(vec[1]);
        }

        bool visit[100005];
        memset(visit, 0, sizeof(visit));
        
        queue<int> que;
        que.push(start);
        visit[start] = true;

        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            for(auto& son : edges[cur])
            {
                if(son == target)
                    return true;
                if(!visit[son])
                {
                    cout<<son<<endl;
                    que.push(son);
                    visit[son] = true;
                }
            }
        }

        return false;
    }
};
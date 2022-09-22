// 2368. 受限条件下可到达节点的数目

class Solution {
public:
    vector<int> edgess[100005];
    bool vis[100005];
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        for(auto& edge : edges) {
            edgess[edge[0]].push_back(edge[1]);
            edgess[edge[1]].push_back(edge[0]);
        }
        int ans = 1;
        vis[0] = true;
        queue<int> que;
        que.push(0);

        for(int res : restricted)
            vis[res] = true;

        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(int next : edgess[cur])
            {
                if(!vis[next])
                {
                    vis[next] = true;
                    que.push(next);
                    ++ans;
                }
            }
        }

        return ans;
    }
};
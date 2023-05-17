class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        
        typedef pair<int, int> pii;

        vector<pii> idxToNode;
        map<pii, int> nodeToIdx;

        auto insertToNode = [&](int x, int y) -> void {

            pii t = make_pair(x, y);
            if(nodeToIdx.count(t) == 0)
            {
                idxToNode.emplace_back(t);
                nodeToIdx[t] = idxToNode.size() - 1;
            }
        };

        insertToNode(start[0], start[1]);
        insertToNode(target[0], target[1]);

        if(idxToNode.size() == 1)
            return 0;

        for(auto& sp : specialRoads)
        {
            insertToNode(sp[0], sp[1]);
            insertToNode(sp[2], sp[3]);
        }

        int n = idxToNode.size();
        int edgeMat[n][n];
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                auto [x1, y1] = idxToNode[i];
                auto [x2, y2] = idxToNode[j];
                edgeMat[i][j] = abs(x1 - x2) + abs(y1 - y2);
            }
        }

        for(auto& sp : specialRoads)
        {
            int i = nodeToIdx[make_pair(sp[0], sp[1])];
            int j = nodeToIdx[make_pair(sp[2], sp[3])];
            edgeMat[i][j] = min(edgeMat[i][j], sp[4]);
            // edgeMat[j][i] = min(edgeMat[j][i], sp[4]);
        }

        int dis[n];
        memset(dis, 0x3f, sizeof(dis));
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        dis[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            int x = -1;
            for(int j = 0; j < n; ++j)
            {
                if(!vis[j] && (x == -1 || dis[j] < dis[x]))
                    x = j;
            }
            vis[x] = true;
            if(x == 1)
                break;
            for(int j = 0; j < n; ++j)
            {
                dis[j] = min(dis[j], dis[x] + edgeMat[x][j]);
            }
        }

        return dis[1];

    }
};
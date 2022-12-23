class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        
        unordered_set<int> edgess[n + 1];


        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace(edge[1]);
            edgess[edge[1]].emplace(edge[0]);
        }

        vector<int> oddNode;
        for(int i = 1; i <= n; ++i)
        {
            if(edgess[i].size() & 1)
            {
                oddNode.emplace_back(i);
                // printf("%d\n", i);
            }
        }

        auto checkNoEdge = [&](int x, int y) -> bool {

            if(edgess[x].count(y) == 1)
                return false;
            return true;
        };

        if(oddNode.size() == 0)
        {
            return true;
        }
        else if(oddNode.size() == 2)
        {
            if(checkNoEdge(oddNode[0], oddNode[1]))
                return true;
            for(int i = 1; i < n; ++i)
                if(checkNoEdge(i, oddNode[0]) && checkNoEdge(i, oddNode[1]))
                    return true;
            return false;
        }
        else if(oddNode.size() == 4)
        {
            if(checkNoEdge(oddNode[0], oddNode[1]) && checkNoEdge(oddNode[2], oddNode[3]))
                return true;
            if(checkNoEdge(oddNode[0], oddNode[2]) && checkNoEdge(oddNode[1], oddNode[3]))
                return true;
            if(checkNoEdge(oddNode[0], oddNode[3]) && checkNoEdge(oddNode[2], oddNode[1]))
                return true;
            return false;
        }
        else
        {
            return false;
        }

    }
};
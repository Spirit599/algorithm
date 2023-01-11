class Solution {
public:
    int findFa(int fa[], int cur) {

        while(fa[cur] != -1)
            cur = fa[cur];
        return cur;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        int indegress[n + 1];
        memset(indegress, -1, sizeof(indegress));

        int from1;
        int from2;
        int to = -1;
        bool haveDouble = false;

        for(auto& edge : edges)
        {
            if(indegress[edge[1]] != -1)
            {
                from1 = indegress[edge[1]];
                from2 = edge[0];
                to = edge[1];
                haveDouble = true;
                break;
            }
            indegress[edge[1]] = edge[0];
        }

        int fa[n + 1];
        memset(fa, -1, sizeof(fa));

        for(auto& edge : edges)
        {
            if(edge[1] == to)
                continue;
            int a = edge[0];
            int b = edge[1];
            int f1 = findFa(fa, a);
            int f2 = findFa(fa, b);
            if(f1 == f2)
                return edge;
            fa[f1] = f2;
        }

        if(findFa(fa, from1) == findFa(fa, to))
            return {from1, to};
        else
            return {from2, to};
        
    }
};
class Solution {
public:
    int findFa(int fa[], int cur) {

        while(fa[cur] != -1)
            cur = fa[cur];
        return cur;
    }
    void unionFa(int fa[], int height[], int a, int b) {

        if(height[a] > height[b])
            fa[b] = a;
        else if(height[a] < height[b])
            fa[a] = b;
        else
        {
            fa[a] = b;
            ++height[b];
        }
    } 
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        int fa1[n + 1];
        int height1[n + 1];
        int fa2[n + 1];
        int height2[n + 1];
        memset(fa1, -1, sizeof(fa1));
        memset(height1, 0, sizeof(height1));
        int ans = 0;

        for(auto& edge : edges)
        {
            if(edge[0] != 3)
                continue;
            int a = edge[1];
            int b = edge[2];
            int fa = findFa(fa1, a);
            int fb = findFa(fa1, b);
            if(fa == fb)
                ++ans;
            else
                unionFa(fa1, height1, fa, fb);
        }

        memcpy(fa2, fa1, sizeof(fa2));
        memcpy(height2, height1, sizeof(height2));
        for(auto& edge : edges)
        {
            int a = edge[1];
            int b = edge[2];
            if(edge[0] == 1)
            {
                int fa = findFa(fa1, a);
                int fb = findFa(fa1, b);
                if(fa == fb)
                    ++ans;
                else
                    unionFa(fa1, height1, fa, fb);
            }
            else if(edge[0] == 2)
            {
                int fa = findFa(fa2, a);
                int fb = findFa(fa2, b);
                if(fa == fb)
                    ++ans;
                else
                    unionFa(fa2, height2, fa, fb);
            }
        }

        int islation = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(fa1[i] == -1)
                ++islation;
            if(fa2[i] == -1)
                ++islation;
        }

        if(islation == 2)
            return ans;
        else
            return -1;
    }
};
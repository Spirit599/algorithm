// 求所有节点的高度
// 树的直径
class Solution {
public:
    struct nodeInfo
    {
        int firstMax = 0;
        int firstMaxIndex = -1;
        int secondMax = 0;
    };
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        nodeInfo info[n];

        int height[n];
        memset(height, 0, sizeof(height));
        vector<int> edgess[n];
        for(auto& edge : edges)
        {
            edgess[edge[0]].push_back(edge[1]);
            edgess[edge[1]].push_back(edge[0]);
        }

        function<int(int, int)> dfsForHeight = [&](int fa, int cur) -> int {

            nodeInfo curInfo;
            for(int next : edgess[cur])
            {
                if(next == fa)
                    continue;
                int curLength = dfsForHeight(cur, next);
                if(curLength > curInfo.firstMax)
                {
                    curInfo.secondMax = curInfo.firstMax;
                    curInfo.firstMax = curLength;
                    curInfo.firstMaxIndex = next;
                }
                else if(curLength > curInfo.secondMax)
                {
                    curInfo.secondMax = curLength;
                }
            }

            info[cur] = curInfo;
            return height[cur] = curInfo.firstMax + 1;
        };
        dfsForHeight(-1, 0);

        function<void(int, int, int)> dfsForRes = [&](int fa, int cur, int maxLength) {


            height[cur] = max(height[cur], maxLength + 1);
            for(int next : edgess[cur])
            {
                if(next == fa)
                    continue;
                if(next != info[cur].firstMaxIndex)
                {
                    dfsForRes(cur, next, max(maxLength, info[cur].firstMax) + 1);
                }
                else
                {
                    // printf("%d %d %d\n",next, cur, info[cur].secondMax);
                    dfsForRes(cur, next, max(maxLength, info[cur].secondMax) + 1);
                }
            }
        };

        dfsForRes(-1, 0, 0);



        vector<int> ret;
        int minn = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            // printf("%d ", height[i]);
            minn = min(minn, height[i]);
        }
        for(int i = 0; i < n; ++i)
            if(minn == height[i])
                ret.push_back(i);

        return ret;
    }
};
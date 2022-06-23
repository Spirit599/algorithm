// 1565 · 飞行棋 I

class Solution {
public:
    /**
     * @param length: the length of board
     * @param connections: the connections of the positions
     * @return: the minimum steps to reach the end
     */
    int modernLudo(int length, vector<vector<int>> &connections) {
        
        bool visit[length + 1];
        memset(visit, 0, sizeof(visit));

        vector<int> edges[length + 1];
        for(vector<int>& v1 : connections)
            edges[v1[0]].push_back(v1[1]);

        queue<int> que;
        que.push(1);
        visit[1] = true;
        int depth = 0;

        while(!que.empty())
        {
            ++depth;
            int k = que.size();
            
            while(k--)
            {

                int cur = que.front();
                que.pop();

                if(cur == length)
                    return depth - 1;

                queue<int> find;
                for(int i = 1; i <= 6; ++i)
                {
                    if(cur + i <= length && !visit[cur + i])
                    {
                        find.push(cur + i);
                        visit[cur + i] = true;
                    }
                }

                while(!find.empty())
                {
                    int cur = find.front();
                    find.pop();
                    que.push(cur);

                    for(int index : edges[cur])
                    {
                        if(!visit[index])
                        {
                            visit[index] = true;
                            find.push(index);
                        }
                    }
                }
            }
        }

        return -1;

    }
};
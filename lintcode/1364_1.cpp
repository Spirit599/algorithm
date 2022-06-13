//bfs
//1364 · 最短路径
//传送门


class Solution {
public:
    /**
     * @param mazeMap: a 2D grid
     * @return: return the minium distance
     */
    int getMinDistance(vector<vector<int>> &mazeMap) {
        
        unordered_map<int, vector<pair<int, int>>> transform;

        int y = mazeMap.size();
        int x = mazeMap[0].size();
        pair<int, int> start;
        for(int i = 0; i < y; ++i)
        {
            for(int j = 0; j < x; ++j)
            {
                if(mazeMap[i][j] > 0)
                {
                    transform[mazeMap[i][j]].push_back(make_pair(i, j));
                }
                if(mazeMap[i][j] == -2)
                {
                    start.first = i;
                    start.second = j;
                }
            }
        }

        queue<pair<int, int>> que;
        que.push(start);
        int depth = 0;
        int dires[] = {-1, 0, 1, 0, -1};
        bool visited[500][500];
        memset(visited, 0, sizeof(visited));
        unordered_set<int> visited_key;

        while(!que.empty())
        {
            int k = que.size();
            ++depth;
            while(k--)
            {
                pair<int, int> cur = que.front();
                que.pop();

                for(int l = 0; l < 4; ++l)
                {
                    int di = cur.first + dires[l];
                    int dj = cur.second + dires[l + 1];
                    if(di < 0 || di >= y || dj < 0 || dj >= x)
                        continue;
                    
                    if(mazeMap[di][dj] == -3)
                    {
                        return depth;
                    }
                    else if(mazeMap[di][dj] == 0 || mazeMap[di][dj] > 0)
                    {
                        if(!visited[di][dj])
                        {
                            
                            visited[di][dj] = true;
                            que.push(make_pair(di, dj));
                        }
                    }
                }

                if(visited_key.count(mazeMap[cur.first][cur.second]) == 0 && mazeMap[cur.first][cur.second] > 0)
                {
                    for(auto& pii : transform[mazeMap[cur.first][cur.second]])
                    {
                        if(cur != pii && !visited[pii.first][pii.second])
                        {
                            visited[pii.first][pii.second] = true;
                            que.push(pii);
                            visited_key.insert(mazeMap[cur.first][cur.second]);
                        }
                    }
                }

            }
        }

        return -1;

    }
};
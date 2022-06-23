// 1832 · 最小步数

class Solution {
public:
    /**
     * @param colors: the colors of grids
     * @return: return the minimum step from position 0 to position n - 1
     */
    int minimumStep(vector<int> &colors) {
        
        int n = colors.size();
        bool visit[n];
        memset(visit, 0, sizeof(visit));
        unordered_map<int, vector<int>> memo;
        unordered_set<int> visit_color;

        for(int i = 0; i < n; ++i)
            memo[colors[i]].push_back(i);

        queue<int> que;
        que.push(0);
        visit[0] = true;
        int depth = 0;
        while(!que.empty())
        {
            int k = que.size();
            ++depth;
            while(k--)
            {
                int cur = que.front();

                if(cur  == n - 1)
                    return depth - 1;
                que.pop();

                if(!visit[cur + 1])
                {
                    que.push(cur + 1);
                    visit[cur + 1] = true;
                }
                if(cur - 1 >= 0 && !visit[cur - 1])
                {
                    que.push(cur - 1);
                    visit[cur - 1] = true;
                }

                if(visit_color.count(colors[cur]) == 0)
                {
                    for(int num : memo[colors[cur]])
                    {
                        if(!visit[num])
                        {
                            que.push(num);
                            visit[num] = true;
                        }
                    }
                    visit_color.insert(colors[cur]);
                }

                //cout<<cur<<" ";
            }
            //cout<<endl;
        }

        return -1;
    }
};
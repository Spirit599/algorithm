//1259 · 整数替换

class Solution {
public:
    /**
     * @param n: a positive integer 
     * @return: the minimum number of replacements
     */
    int integerReplacement(int n) {
        
        unordered_set<int> visited;
        queue<int> que;
        que.emplace(n);

        int depth = -1;
        while(!que.empty())
        {
            ++depth;
            int k = que.size();
            while(k--)
            {
                int cur = que.front();
                if(cur == 1)
                    return depth;
                que.pop();

                if(cur & 1)
                {
                    if(visited.count(cur + 1) == 0)
                        que.emplace(cur + 1);
                    if(visited.count(cur - 1) == 0)
                        que.emplace(cur - 1);
                }
                else
                {
                    if(visited.count(cur / 2) == 0)
                        que.emplace(cur / 2);
                }
            }
        }

        return -1;
    }
};
class Solution {
public:
    int kSimilarity(string s1, string s2) {

        queue<pair<string, int>> que;
        unordered_set<string> vis;

        que.emplace(s1, 0);
        int time = 0;
        int n = s1.size();

        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                string cur = que.front().first;
                int idx = que.front().second;

                if(cur == s2)
                    return time;
                que.pop();
                while(idx < n && cur[idx] == s2[idx])
                    ++idx;
                for(int i = idx + 1; i < n; ++i)
                {
                    if(cur[i] == s2[idx] && s2[idx] != s2[i])
                    {
                        swap(cur[i], cur[idx]);
                        if(!vis.count(cur))
                        {
                            vis.insert(cur);
                            que.emplace(cur, idx + 1);
                        }
                        swap(cur[i], cur[idx]);
                    }
                }
            }
            ++time;
        }

        return -1;
    }
};
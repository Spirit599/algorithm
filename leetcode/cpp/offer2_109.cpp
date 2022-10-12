class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> vis;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        queue<string> que;
        if(dead.count("0000") == 0)
            que.push("0000");
        int ans = -1;

        while(!que.empty())
        {
            int k = que.size();
            ++ans;
            while(k--)
            {   
                string cur = que.front();
                if(cur == target)
                    return ans;
                
                que.pop();
                int n = cur.size();
                for(int i = 0; i < n; ++i)
                {
                    char pre = cur[i];
                    cur[i] = (pre - '0' + 1) % 10 + '0';
                    if(vis.count(cur) == 0 && dead.count(cur) == 0)
                    {
                        vis.insert(cur);
                        que.push(cur);
                    }
                    cur[i] = (pre - '0' + 9) % 10 + '0';
                    if(vis.count(cur) == 0 && dead.count(cur) == 0)
                    {
                        vis.insert(cur);
                        que.push(cur);
                    }
                    cur[i] = pre;
                }
            }

        }


        return -1;
    }
};
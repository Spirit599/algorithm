class Solution {
public:
    string alienOrder(vector<string>& words) {

        int n = 26;
        vector<int> edges[n];
        int indegress[n];
        bool cnt[n];
        memset(cnt, 0, sizeof(cnt));
        memset(indegress, 0, sizeof(indegress));
        bool valid = true;

        int m = words.size();
        auto addEdge = [&](int i, int j) {

            int n1 = words[i].size();
            int n2 = words[j].size();
            int n = min(n1, n2);

            for(int k = 0; k < n; ++k)
            {
                if(words[i][k] != words[j][k])
                {
                    edges[words[i][k] - 'a'].emplace_back(words[j][k] - 'a');
                    ++indegress[words[j][k] - 'a'];
                    return ;
                }
            }

            if(n1 > n2)
                valid = false;
        };

        for(int i = 0; i < m - 1; ++i)
        {
            addEdge(i, i + 1);
            if(!valid)
                return "";
        }

        for(int i = 0; i < m; ++i)
        {
            int k = words[i].size();
            for(int j = 0; j < k; ++j)
                cnt[words[i][j] - 'a'] = true;
        }

        int remain = 0;
        for(int i = 0; i < n; ++i)
        {
            if(cnt[i])
                ++remain;
        }

        queue<int> que;
        string ans;
        for(int i = 0; i < n; ++i)
        {
            if(cnt[i] && indegress[i] == 0)
            {
                --remain;
                que.emplace(i);
                ans.push_back(i + 'a');
            }
        }

        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                int cur = que.front();
                que.pop();
                for(int next : edges[cur])
                {
                    --indegress[next];
                    if(indegress[next] == 0)
                    {
                        que.emplace(next);
                        ans.push_back(next + 'a');
                        --remain;
                    }
                }
            }
        }


        if(remain == 0)
            return ans;
        else
            return "";
    }
};
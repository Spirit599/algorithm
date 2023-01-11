class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        int endIndex = -1;
        wordList.emplace_back(beginWord);
        int n = wordList.size();
        int startIndex = n - 1;
        int strSize = beginWord.size();

        for(int i = 0; i < n; ++i)
        {
            if(wordList[i] == endWord)
            {
                endIndex = i;
                break;
            }
        }

        vector<vector<string>> ret;
        if(endIndex == -1)
            return ret;

        vector<int> edges[n];
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        auto checkOk = [&](int i, int j) {

            int dif = 0;
            for(int k = 0; k < strSize; ++k)
            {
                if(wordList[i][k] != wordList[j][k])
                {
                    ++dif;
                    if(dif == 2)
                        return false;
                }
            }
            return true;
        };

        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(checkOk(i, j))
                {
                    edges[i].emplace_back(j);
                    edges[j].emplace_back(i);
                }
            }
        }

        queue<int> que;
        que.emplace(startIndex);
        vis[startIndex] = true;

        set<int> onceVis;
        vector<int> edgess[n];

        bool isFind = false;
        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                int cur = que.front();
                que.pop();
                if(cur == endIndex)
                {
                    isFind = true;
                    break;
                }
                for(int next : edges[cur])
                {
                    if(!vis[next])
                    {
                        if(!onceVis.count(next))
                            que.emplace(next);
                        onceVis.insert(next);
                        edgess[next].emplace_back(cur);
                    }
                }
            }
            if(isFind)
                break;
            for(auto& v : onceVis)
                vis[v] = true;
            onceVis.clear();
        }

        
        vector<string> cur({wordList[endIndex]});
        function<void(int)> dfs = [&](int index) {

            if(index == startIndex)
            {
                ret.emplace_back(cur);
                return ;
            }

            for(int next : edgess[index])
            {
                cur.emplace_back(wordList[next]);
                dfs(next);
                cur.pop_back();
            }
        };

        dfs(endIndex);

        for(auto& v : ret)
            reverse(v.begin(), v.end());

        return ret;
    }
};
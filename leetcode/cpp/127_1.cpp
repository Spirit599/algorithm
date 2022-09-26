// 127. 单词接龙
// bfs

class Solution {
public:
    vector<int> edges[5005];
    bool vis[5005];
    bool checkEdge(const string& str1, const string& str2) const
    {
        int dif = 0;
        int n = str1.size();
        for(int i = 0; i < n; ++i)
        {
            if(str1[i] != str2[i])
                ++dif;
            if(dif == 2)
                return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();
        int startIndex = n;
        wordList.push_back(beginWord);
        int endIndex = -1;
        for(int i = 0; i <= n; ++i)
        {
            if(wordList[i] == endWord)
                endIndex = i;
            for(int j = i + 1; j <= n; ++j)
            {
                if(checkEdge(wordList[i], wordList[j]))
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        if(endIndex == -1)
            return 0;

        int ans = 1;
        memset(vis, 0, sizeof(vis));
        queue<int> que;
        que.push(startIndex);
        vis[startIndex] = true;

        while(!que.empty())
        {
            int k = que.size();
            ++ans;
            while(k--)
            {
                int cur = que.front();
                que.pop();
                for(int next : edges[cur])
                {
                    if(next == endIndex)
                        return ans;
                    if(!vis[next])
                    {
                        que.push(next);
                        vis[next] = true;
                    }
                }
            }
        }

        return 0;
    }
};

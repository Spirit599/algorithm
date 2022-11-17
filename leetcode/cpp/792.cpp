// 多指针

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        
        queue<pair<int ,int>> queues[26];
        int n = words.size();
        for(int i = 0; i < n; ++i)
        {
            queues[words[i][0] - 'a'].emplace(i, 0);
        }

        int ans = 0;
        for(char c : s)
        {
            auto& que = queues[c - 'a'];
            int k = que.size();
            while(k--)
            {
                auto [x, y] = que.front();
                que.pop();
                ++y;
                if(y == words[x].size())
                    ++ans;
                else
                {
                    queues[words[x][y] - 'a'].emplace(x, y);
                }
            }
        }

        return ans;
    }
};
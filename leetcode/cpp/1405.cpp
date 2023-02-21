typedef pair<int, char> pic;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pic> pq;
        if(a > 0)
            pq.emplace(a, 'a');
        if(b > 0)
            pq.emplace(b, 'b');
        if(c > 0)
            pq.emplace(c, 'c');

        string ans;
        while(!pq.empty())
        {
            auto [cnt, c] = pq.top();
            pq.pop();
            int k = ans.size();
            if(k >= 2 && ans[k - 1] == c && ans[k - 2] == c)
            {
                if(pq.empty())
                    break;
                auto [cnt2, c2] = pq.top();
                pq.pop();
                ans.push_back(c2);
                if(--cnt2 != 0)
                    pq.emplace(cnt2, c2);
                pq.emplace(cnt, c);
            }
            else
            {
                ans.push_back(c);
                if(--cnt != 0)
                    pq.emplace(cnt, c);
            }
        }

        return ans;
    }
};
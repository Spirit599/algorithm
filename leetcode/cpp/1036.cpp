struct pairHashFunc
{
    template<typename T, typename U>
    size_t operator()(const std::pair<T, U>& p) const {
    return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
    }
};

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {

        unordered_set<pair<int, int>, pairHashFunc> vis;
        unordered_set<pair<int, int>, pairHashFunc> recordBlock;
        for(auto& block : blocked)
            recordBlock.insert(make_pair(block[0], block[1]));

        int n = 999999;
        int dires[] = {-1, 0, 1, 0, -1};
        int blockedSize = blocked.size();
        int upLimit = blockedSize * blockedSize / 2;

        int cur = 0;
        queue<pair<int ,int>> que;
        que.emplace(source[0], source[1]);
        while(!que.empty())
        {
            auto [x, y] = que.front();
            // printf("%d %d\n", x,y);
            que.pop();
            if(x == target[0] && y == target[1])
                return true;
            if(cur == upLimit)
                break;
            for(int k = 0; k < 4; ++k)
            {
                int i = x + dires[k];
                int j = y + dires[k + 1];
                if(i < 0 || i > n || j < 0 || j > n)
                    continue;
                if(!recordBlock.count(make_pair(i, j)) && !vis.count(make_pair(i, j)))
                {
                    que.emplace(i, j);
                    vis.emplace(i, j);
                }
            }
            ++cur;
        }

        int cur1 = 0;
        vis.clear();
        queue<pair<int ,int>> que1;
        que1.emplace(target[0], target[1]);
        while(!que1.empty())
        {
            auto [x, y] = que1.front();
            // printf("x %d %d\n", x,y);
            que1.pop();
            if(cur1 == upLimit)
                break;
            for(int k = 0; k < 4; ++k)
            {
                int i = x + dires[k];
                int j = y + dires[k + 1];
                if(i < 0 || i > n || j < 0 || j > n)
                    continue;
                if(!recordBlock.count(make_pair(i, j)) && !vis.count(make_pair(i, j)))
                {
                    que1.emplace(i, j);
                    vis.emplace(i, j);
                }
            }
            ++cur1;
        }


        // printf("%d %d %d\n", cur, cur1, upLimit);

        return cur == upLimit && cur1 == upLimit;
    }
};
struct pairHashFunc
{
    template<typename T, typename U>
    size_t operator()(const std::pair<T, U>& p) const {
    return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
    }
};

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        unordered_map<int, int> row;
        unordered_map<int, int> col;
        unordered_map<int, int> diagonal1;
        unordered_map<int, int> diagonal2;
        unordered_set<pair<int, int>, pairHashFunc> memo;

        for(auto& lamp : lamps)
        {
            int x = lamp[0];
            int y = lamp[1];
            if(memo.count(make_pair(x, y)) == 1)
                continue;
            ++row[x];
            ++col[y];
            ++diagonal1[x + y];
            ++diagonal2[x - y + n];
            memo.emplace(x, y);
        }

        auto eraseLamp = [&](int x, int y) {

            auto it = memo.find(make_pair(x, y));
            if(it == memo.end())
                return;
            memo.erase(it);
            --row[x];
            --col[y];
            --diagonal1[x + y];
            --diagonal2[x - y + n];
        };

        vector<int> ret;
        for(auto& query : queries)
        {
            int x = query[0];
            int y = query[1];
            if(row[x] || col[y] || diagonal1[x + y] || diagonal2[x - y + n])
            {
                eraseLamp(x, y);
                eraseLamp(x, y + 1);
                eraseLamp(x, y - 1);
                eraseLamp(x + 1, y);
                eraseLamp(x - 1, y);
                eraseLamp(x - 1, y + 1);
                eraseLamp(x - 1, y - 1);
                eraseLamp(x + 1, y + 1);
                eraseLamp(x + 1, y - 1);
                ret.emplace_back(1);
            }
            else
            {
                ret.emplace_back(0);
            }
        }

        return ret;


    }
};
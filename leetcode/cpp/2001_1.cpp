class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {

        long long ret = 0;
        unordered_map<double, long long> um;

        for (auto& rect : rectangles)
        {
            double key = (double)rect[0] / (double)rect[1];

            auto it = um.find(key);
            if(it != um.end())
            {
                (it->second)++;
            }
            else
            {
                um.insert({key, 1});
            }
        }

        for (auto& rect : um)
        {
            cout<<rect.first<<endl;
            if(rect.second >= 1)
            {
                ret += rect.second * (rect.second - 1) / 2;
            }
        }

        return ret;
    }
};
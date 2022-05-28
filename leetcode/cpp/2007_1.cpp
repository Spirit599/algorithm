bool cmp(const int& a, const int& b)
{
    return a > b;
}

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        if(changed.size() % 2 != 0)
            return vector<int>();

        unordered_map<int ,int> hash;
        vector<int> ret;

        sort(changed.begin(), changed.end(), cmp);

        for(auto& key : changed)
        {
            auto it = hash.find(key * 2);
            if(it != hash.end())
            {
                if(it->second == 0)
                    hash.erase(key * 2);
                else
                    --(it->second);
                ret.push_back(key);
            }
            else
            {
                auto i = hash.find(key);
                if(i != hash.end())
                {
                    ++(i->second);
                }
                else
                {
                    hash.insert({key, 0});
                }
            }
        }

        if(ret.size() == changed.size() / 2)
            return ret;
        else
            return vector<int>();
    }
};